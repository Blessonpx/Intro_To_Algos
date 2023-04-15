#include <iostream>
#include <boost/heap/priority_queue.hpp>
#include <boost/array.hpp>
#include <algorithm>

using namespace std;

int main()
{
    boost::array<int, 6> arr = {5, 7, 2, 8, 4, 9};
    std::make_heap(arr.begin(), arr.end());
    boost::heap::priority_queue<int> pq;

    // Initialize priority queue from Boost array
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        pq.push(*it);
    }

    // Insert
    auto h = pq.emplace(3);
    cout << "After inserting 3, the max value is: " << pq.top() << endl;

    // Maximum
    cout << "The max value is: " << pq.top() << endl;

    // Extract Max
    pq.pop();
    cout << "After extracting max, the new max value is: " << pq.top() << endl;

    // Increase Key
    h = pq.emplace(7);
    pq.update(h, 10);
    cout << "After increasing key, the max value is: " << pq.top() << endl;

    return 0;
}
