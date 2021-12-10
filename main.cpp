//Group 10: Caleb Harmon, Daniel Nagy, Jerry Deligiannis, Lewis McLean, Luca Zen, & Sandy Steuart Fothringham
//Simulator Team: Caleb Harmon, Luca Zen, Sandy Steuart Fothringham
//File Authors: Caleb Harmon

#include "simulator.cpp"
#include <string>
using namespace std;

int main(){
    //add test programs
    //test 5+3
    //test
    bool exit = false;
    int check = 1;
    string fileName;
    cout << "Enter a file name to run the simulator" << endl;
    cin >> fileName;

    if(!exists(fileName)){
        cout << "Error loading file - file may not exist" << endl;
        
    }else{
        initStore();
        loadFromFile(fileName);
        check = run();
    }
 
    if(check == 0){
        string yorn;
        cout << "Program Successfully Ran, would you like to output the store? (y/n)" << endl;
        cin >> yorn;
        if(yorn == "y"|| yorn == "Y"){
            displayStore();
        }
    }
       
}