//Group 10: Caleb Harmon, Daniel Nagy, Jerry Deligiannis, Lewis McLean, Luca Zen, & Sandy Steuart Fothringham
//Simulator Team: Caleb Harmon, Luca Zen, Sandy Steuart Fothringham
//File Authors: Caleb Harmon, Sandy Steuart Fothringham

#include "simulator.cpp"
#include <string>
using namespace std;
void fileInput();
void runSamples();


int main(){

    int choice;
    while (choice != 3)
    {
        //menu options
        cout << "1. Run Manchester Baby Simulator (Choosing own file)" << endl;
        cout << "2. Run Sample Program" << endl;
        cout << "3. Exit " << endl;
        cout << "Option: ";

        //getting user input and selecting correct choice
        cin >> choice;

        switch (choice)
        {
        case 1:
            fileInput();
            break;
        case 2:
            runSamples();
            break;
        case 3:
            cout << "Exiting..." << endl;
            return 0;
            break;

        default:
            cout << "Invalid input\n"
                 << endl;
            cout << "" << endl;
        }
        //clearing cin
        cin.clear();
        cin.ignore(10000, '\n');
    }
  
}

//chooses a file for the simulator to run
void fileInput(){
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

        cout << "Program Successful" << endl;
        
        }
    }

//Lists available sample programs for the simulator to run.
void fileInput(){
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

        cout << "Program Successful" << endl;
        
        }
    }

void runSamples(){
    int choice;
    cout << "Choose a sample program to run (End result shown in accumulator)" << endl;
    cout << "1. Run Sample 1 (Add 5 + 3)" << endl;
    cout << "2. Run Sample 2 ( Add 53 + 789) " << endl;
    cout << "3. Run 'BabyTest1-MC.txt' " << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            initStore();
            loadFromFile("Sample1.txt");
            run();
            break;
        case 2:
            initStore();
            loadFromFile("Sample2.txt");
            run();
            break;
        case 3:
            initStore();
            loadFromFile("BabyTest1-MC.txt");
            run();
            break;
        case 4:
            break;
        default:
             cout << "Invalid input\n"
                 << endl;
            cout << "" << endl;
    }

}
