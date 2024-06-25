#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <utility> // move
#include <vector> // vector

template <typename T>
struct Node {
    T val;
    std::vector<Node<T>*> children;

    explicit Node(T val, std::vector<Node<T>*> children = {})
        : val{val}, children{children} {}
};

void dfs(Node<int>* root, std::vector<std::string> path, std::vector<std::string>& res) {
    if (root->children.size() == 0) {
       path.emplace_back(std::to_string(root->val));
       std::string s = "";
       for (int i = 0; i < path.size(); i++) {
           if (i == path.size() - 1) {
               s += path[i];
           } else {
               s += path[i] + "->";
            }
        }
        res.emplace_back(s);
        return;
    }
    for (auto& child: root->children) {
        if (child) {
            std::vector<std::string> path_copy(path);
            path_copy.emplace_back(std::to_string(root->val));
            dfs(child, path_copy, res);
        }
    }
}

std::vector<std::string> ternary_tree_paths(Node<int>* root) {
    std::vector<std::string> res;
    if (root) dfs(root, {}, res);
    return res;
}

// this function builds a tree from input; you don't have to modify it
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;

    ++it;
    int num = std::stoi(*it);
    ++it;
    std::vector<Node<T>*> children;
    for (int i = 0; i < num; i++)
        children.emplace_back(build_tree<T>(it, f));
    return new Node<T>{f(val), std::move(children)};
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<std::string> root_vec = get_words<std::string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return std::stoi(s); });
    std::vector<std::string> res = ternary_tree_paths(root);
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}
