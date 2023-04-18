#include <iostream>
#include <boost/array.hpp>

using namespace std;

template <typename T, size_t N>
int partition(boost::array<T, N>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

template <typename T, size_t N>
void quicksort(boost::array<T, N>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    boost::array<int, 6> arr = {5, 2, 3, 1, 6, 4};
    quicksort(arr, 0, 5);
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}