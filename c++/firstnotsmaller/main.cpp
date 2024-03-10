// Find first element in a sorted array >= target value
//
// Given an array of ints { 2,3,4,6,6,7,8,8 } with target 5 return 3
//

#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int first_not_smaller(std::vector<int> vec, int target) {
    unsigned long right = vec.size() - 1;
    unsigned long left = 0;
    unsigned long mid = 0;
    long index = -1;

    while (left <= right) {
        mid = static_cast<unsigned long>(left + (right-left) / 2);
        if (vec[mid] >= target) {
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> arr = get_words<int>();

    int target;
    std::cin >> target;
    ignore_line();
    int res = first_not_smaller(arr, target);
    std::cout << res << '\n';
}