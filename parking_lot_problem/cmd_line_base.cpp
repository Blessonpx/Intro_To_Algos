#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Define a vector of commands that the application will accept
    vector<string> commands = {"print", "save", "exit"};
    cout<<"Commands Valid:: Print,Save,Exit "<<endl;

    // Start an interactive shell that accepts commands from the user
    string input;
    bool running = true;
    while (running) {
        // Accept input from the user
        cout << "> ";
        getline(cin, input);

        // Parse the input to determine which command was entered and any arguments
        string command;
        vector<string> args;
        size_t pos = input.find(' ');
        if (pos != string::npos) {
            command = input.substr(0, pos);
            string argstr = input.substr(pos + 1);
            pos = argstr.find(' ');
            while (pos != string::npos) {
                args.push_back(argstr.substr(0, pos));
                argstr = argstr.substr(pos + 1);
                pos = argstr.find(' ');
            }
            args.push_back(argstr);
        } else {
            command = input;
        }

        // Process the command
        if (command == "print") {
            cout << "Printing some data..." << endl;
        } else if (command == "save") {
            if (args.size() < 2) {
                cout << "Usage: save <filename> <data>" << endl;
            } else {
                string filename = args[0];
                string data = args[1];
                ofstream outfile(filename);
                outfile << data << endl;
                outfile.close();
                cout << "Data saved to " << filename << endl;
            }
        } else if (command == "exit") {
            running = false;
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}
