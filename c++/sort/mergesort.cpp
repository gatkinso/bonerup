#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <chrono>

using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

class ISort {
public:
    virtual milliseconds sort() = 0;
    virtual std::string name() = 0;
};

class SortBase : public ISort {
protected:
    std::vector<double> doubleArray;
    int size;

    virtual void sortImpl() = 0;

public:
    SortBase(int size) : size(size), doubleArray(size) {
        for (int i = 0; i < this->size; i++) {
            this->doubleArray[i] = static_cast<double>(rand()) / RAND_MAX * 1000000.0;
        }
    }

    milliseconds sort() override {
        time_point<Clock> start = Clock::now();
        sortImpl();
        return duration_cast<milliseconds>(Clock::now() - start);
    }
};

class MergeSort : public SortBase {
public:
    MergeSort(int size) : SortBase(size) {}

    std::string name() override {
        return "MergeSort";
    }

protected:
    void sortImpl() override {
        mergeSort(this->doubleArray, 0, this->doubleArray.size() - 1);
    }

private:
    void mergeSort(std::vector<double>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    void merge(std::vector<double>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        std::vector<double> L(n1), R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

int main() {

    auto coll = MergeSort(2000000);
    auto dur = coll.sort();

    std::cout << " Sort took: " << dur.count() << std::endl;

    return 0;
}