#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int peak_of_mountain_array(std::vector<int> vec) {
    auto sz = vec.size();
    if(sz == 0) {
        return -1;
    }

    unsigned long right = sz - 1;
    unsigned long left = 0;
    unsigned long mid = 0;
    long index = -1;

    while (left <= right) {
        mid = static_cast<unsigned long>(left + (right-left) / 2);
        if (mid == sz-1 || vec[mid] > vec[mid+1]) {
            index = mid;
            right = mid -1;
        } else {
            left = mid +1;
        }
    }
    return index;
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
    std::vector<int> arr = get_words<int>();
    int res = peak_of_mountain_array(arr);
    std::cout << res << '\n';
}