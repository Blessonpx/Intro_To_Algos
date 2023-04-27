#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string command;
    cout << "Enter command: ";
    getline(cin, command);

    if (command.find("save name") == 0) {
        string name = command.substr(10); // extract the name from the command
        ofstream outfile("names.csv", ios_base::app); // open file in append mode
        outfile << name << endl; // write name to file
        outfile.close(); // close the file
        cout << "Name saved to CSV file." << endl;
    } else {
        cout << "Invalid command." << endl;
    }

    return 0;
}
