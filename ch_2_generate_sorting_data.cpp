#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main()
{
    // Define the number of rows to generate
    int n = 100;

    // Open the output file
    ofstream file("random_data.csv");

    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 1000);

    // Generate and write the random data to the file
    for (int i = 0; i < n; i++)
    {
        int random_number = dist(gen);
        file << random_number << endl;
    }

    // Close the file
    file.close();

    return 0;
}
