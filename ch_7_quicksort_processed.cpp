#include <iostream>
#include <boost/array.hpp>

using namespace std;

template<typename T, std::size_t N>
void quicksort(boost::array<T, N>& arr, int left, int right) {
    int i = left, j = right;
    T pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quicksort(arr, left, j);
    }

    if (i < right) {
        quicksort(arr, i, right);
    }
}

int main() {
    boost::array<int, 6> arr = {5, 7, 2, 8, 4, 9};
    quicksort(arr, 0, arr.size()-1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
