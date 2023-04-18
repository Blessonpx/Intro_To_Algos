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
void counting_sort(boost::array<T, N>& arr_1, boost::array<T, N>& arr_2, int k) {
    boost::array<int, k> arr_c = boost::array<int, k>();
    arr_c.assign(0);
}

int main() {
    boost::array<int, 6> arr_a = {5, 2, 3, 1, 6, 4};
    boost::array<int, 6> arr_b = boost::array<int, 6>();
    counting_sort(arr_a, arr_b, 6);
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}