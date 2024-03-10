#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int square_root(int n) {
    if (n == 0) return 0;
    
    unsigned long right = n;
    unsigned long left = 1;
    unsigned long mid = 0;
    long index = -1;

    while (left <= right) {
        mid = static_cast<unsigned long>(left + (right-left) / 2);
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid > n) {
            right = mid - 1;
            index = mid;
        } else {
            left = mid + 1;
        }
    }
    return index - 1;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = square_root(n);
    std::cout << res << '\n';
}