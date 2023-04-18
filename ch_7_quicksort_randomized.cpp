#include <iostream>
#include <boost/array.hpp>
#include <random>
#include <algorithm>
using namespace std;

int generateRandomInt(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}


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
int random_partition(boost::array<T, N>& arr, int low, int high){
    int i = generateRandomInt(low,high);
    swap(arr[high], arr[i]);
    int meta=partition(arr,low,high);
    return meta;
}



template <typename T, size_t N>
void random_quicksort(boost::array<T, N>& arr, int low, int high) {
    if (low < high) {
        int pi = random_partition(arr, low, high);
        random_quicksort(arr, low, pi - 1);
        random_quicksort(arr, pi + 1, high);
    }
}

int main() {
    boost::array<int, 6> arr = {5, 2, 3, 1, 6, 4};
    random_quicksort(arr, 0, 5);
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}