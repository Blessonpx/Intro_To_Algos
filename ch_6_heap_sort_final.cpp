#include <iostream>
#include <boost/array.hpp>

using namespace std;

void Max_Heapify(boost::array<int,10>& arr,int i,int heap_size ){
    int left_child=2*i+1;
    int right_child=2*i+2;
    int largest=i;

    if(left_child<heap_size && arr[left_child]>arr[largest]){
        largest=left_child;
    }

    if(right_child<heap_size && arr[right_child]>arr[largest]){
        largest=right_child;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        Max_Heapify(arr,largest,heap_size);
    }
}
    void Build_max_heap(boost::array<int, 10>& arr){
        int heap_size = arr.size();
        for(int i=heap_size/2-1;i>=0;i--){
            Max_Heapify(arr,i,heap_size);
        }
    }
    void HeapSort(boost::array<int, 10>& arr){
        Build_max_heap(arr);
        int heap_size = arr.size();
        for (int i = heap_size - 1; i >= 1; i--){
            swap(arr[0], arr[i]);
            heap_size--;
            Max_Heapify(arr, 0, heap_size);
            }
    }
    int main(){
        // Create the Array of size 10 
        boost::array<int, 10> arr = {5, 3, 8, 4, 2, 7, 1, 6, 9, 0};
        // Perform heapsort on the array
        HeapSort(arr);
        // Print the sorted array to the console
        for (int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    }
