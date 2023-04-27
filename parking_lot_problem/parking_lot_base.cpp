#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/array.hpp>

using namespace std;

const int MAX_SIZE=50;

class Parking_Lot{
    private:
        boost::array<string,MAX_SIZE> arr;
        int lot_size;
        int lot_limit;
    public:
        Parking_Lot() {
        lot_size=0;
        }
        void set_lot_size(int n){
            lot_limit=n;
            cout<<"Lot Limit Set to "<<n<<endl;
        }
        void allocate_spot(string car_details){
            if( lot_size>lot_limit){
                cout<<"Parking Lot Full"<<endl;
            }
            else{
                cout<<"car_details:"<<car_details<<endl;
                int i=0;
                for(;i<lot_limit;i++){
                    if(arr[i]=="NA"){
                        arr[i]=car_details;
                        break;
                    }
                }
                if(i==lot_limit){
                    // increment lot_size
                    arr[lot_size]=car_details;
                    cout<<"Car details Inserted"<<endl;
                    lot_size++;
                }
            }
        }
        void list_all(){
            for (int i = 0; i < lot_limit ; i++){
                if(arr[i] != "" && arr[i]!="NA"){
                    cout<<"Lot-"<<i<<" : "<<arr[i]<<endl;
                }
            }
        }
        void leave_spot(int id){
            cout<<"Lot Limit = "<<lot_limit<<endl;
            if(id<lot_limit){  // && (arr[id]!="" || arr[id]!="NA")
                cout<<"Id="<<id<<endl;
                arr[id]="NA";
                lot_size--;
            }else{
                cout<<"Spot Id Invalid or alreafy empty"<<endl;
            }
        }
};


int main()
{
    cout<<"Commands Valid:: create_parking_lot , park , list_cars , leave , exit "<<endl;
    Parking_Lot p;
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
        boost::array<string, 12> arr;
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
        }else if(command == "create_parking_lot"){
            cout<<"create_parking_lot"<<endl;
            try{
                if(args[0]==""){
                    throw "No Size argument given for creating parking lot ";
                }else {
                    cout<<"Parking Lot Size is "<<args[0]<<endl;

                    p.set_lot_size(stoi(args[0]));
                }
            }catch(const char* msg) {
                cerr << "Error:" << msg << endl;
                }
        } else if(command == "park"){
            string car_details = args[0]+"|"+args[1];
            p.allocate_spot(car_details);
        }else if(command == "list_cars"){
            p.list_all();
        }else if(command == "leave"){
            int spot_id=stoi(args[0]);
            p.leave_spot(spot_id);
        }else if (command == "exit") {
            running = false;
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}
