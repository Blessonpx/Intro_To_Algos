#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

// Read data from a CSV file and store it in a vector of integers
vector<int> read_csv(string filename)
{
    ifstream file(filename);
    vector<int> data;
    string line;
    while (getline(file, line))
    {
        vector<string> line_data;
        boost::split(line_data, line, boost::is_any_of(","));
        data.push_back(stoi(line_data[0]));
    }
    return data;
}

// Perform Merge sort on a vector of integers
void merge_sort(vector<int>& data)
{
    if (data.size() > 1)
    {
        int mid = data.size() / 2;
        vector<int> left(data.begin(), data.begin() + mid);
        vector<int> right(data.begin() + mid, data.end());
        merge_sort(left);
        merge_sort(right);
        data.clear();
        merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(data));
    }
}

// Perform Insertion sort on a vector of integers
void insertion_sort(vector<int>& data)
{
    for (int i = 1; i < data.size(); i++)
    {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

int main()
{
    // Read data from the CSV file
    vector<int> data = read_csv("random_data.csv");

    // Perform Merge sort on the data
    vector<int> sorted_data = data;
    merge_sort(sorted_data);

    // Print the sorted data
    cout << "Merge sort:" << endl;
    for (int i : sorted_data)
    {
        cout << i << " ";
    }
    cout << endl;

    // Perform Insertion sort on the data
    sorted_data = data;
    insertion_sort(sorted_data);

    // Print the sorted data
    cout << "Insertion sort:" << endl;
    for (int i : sorted_data)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
