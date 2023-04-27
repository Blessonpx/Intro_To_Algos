#include <iostream>
#include <boost/array.hpp>

using namespace boost;

void countingSort(array<int, 10>& arr) {
    // Find the maximum element in the array
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    
    // Create a count array to store the frequency of each element
    array<int, 11> count = {0};
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }
    
    // Modify the count array to store the cumulative sum of frequencies
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i-1];
    }
    
    // Create a sorted array using the count array
    array<int, 10> sortedArr;
    for (int i = arr.size()-1; i >= 0; i--) {
        sortedArr[--count[arr[i]]] = arr[i];
    }
    
    // Copy the sorted array back to the input array
    arr = sortedArr;
}

int main() {
    // Create a Boost array of integers to sort
    array<int, 10> arr = {9, 2, 5, 4, 8, 1, 7, 6, 3, 0};
    
    // Sort the array using counting sort
    countingSort(arr);
    
    // Print the sorted array
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
