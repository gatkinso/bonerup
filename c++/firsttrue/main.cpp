// Find first true element in a boolean sorted array
//
// Given an array of bools { false, false false, false, true, true } return 3
// This is the most basic of binary searches.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> testvect{ false, false, false, false, true, true, true };

long FindFirst(const vector<bool>& vec) {
    unsigned long right = vec.size() - 1;
    unsigned long left = 0;
    unsigned long mid = 0;
    long index = -1;

    while (left <= right) {
        mid = static_cast<unsigned long>(left + (right-left) / 2);
        if (vec[mid]) {
            index = mid;
            right = mid -1;
        } else {
            left = mid +1;
        }
    }
    return index;
}

void print(ostream& s, const vector<bool>& vec) {
    s << "[";
    for(auto val : vec ) {
        if(val)
            s << " true ";
        else
            s << " false ";
    }
    s << "]";
}

int main(int argc, char* argv[]) {

    auto result = FindFirst(testvect);

    cout << "First true value in array: " << endl;
    print(cout, testvect);
    cout << " is " << result << endl;
    return 0;
}
