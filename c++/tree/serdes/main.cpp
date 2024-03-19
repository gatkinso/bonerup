#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, stoi, string, to_string
#include <vector> // vector

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
        : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};

void serialize_dfs(Node<int>* root, std::vector<std::string>& res) {
    if (root == nullptr) {
        res.emplace_back("x");
        return;
    }
    res.emplace_back(std::to_string(root->val));
    serialize_dfs(root->left, res);
    serialize_dfs(root->right, res);
}

std::string serialize(Node<int>* root) {
    std::vector<std::string> res;
    serialize_dfs(root, res);
    std::stringstream ss;
    std::copy(res.begin(), res.end(), std::ostream_iterator<std::string>(ss, " "));
    return ss.str();
}

Node<int>* deserialize_dfs(std::vector<std::string>::iterator& nodes) {
    std::string val = *nodes;
    ++nodes;
    if (val == "x") return nullptr;
    Node<int>* cur = new Node<int>(std::stoi(val));
    cur->left = deserialize_dfs(nodes);
    cur->right = deserialize_dfs(nodes);
    return cur;
}

Node<int>* deserialize(std::string root) {
    std::istringstream ss(root);
    std::vector<std::string> nodes;
    std::copy(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::back_inserter(nodes));
    auto nodes_iter = nodes.begin();

    return deserialize_dfs(nodes_iter);
}

template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
}

template<typename T, typename F>
void format_tree(Node<T>* node, F f, std::vector<std::string>& out) {
    if (node == nullptr) {
        out.emplace_back("x");
        return;
    }
    out.emplace_back(f(node->val));
    format_tree(node->left, f, out);
    format_tree(node->right, f, out);
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* tree = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    Node<int>* res = deserialize(serialize(tree));
    std::vector<std::string> res_vec;
    format_tree(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}