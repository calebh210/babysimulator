//Group 10: Caleb Harmon, Daniel Nagy, Jerry Deligiannis, Lewis McLean, Luca Zen, & Sandy Steuart Fothringham
//Simulator Team: Caleb Harmon, Luca Zen, Sandy Steuart Fothringham
//File Authors: Caleb Harmon, Luca Zen, Sandy Steuart Fothringham

#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h>
#include "line.h"
#include "simulator.h"
using namespace std;

//setting up registers and other required variables.
int accumulator = 0;
int controlInstruction = 0;
string presentInstruction = "00000000000000000000000000000000";
string store[32];
bool stp = false;



//loads a chosen file into the store.
void loadFromFile(string fileName)
{
    string line;
    int i = 0;

    ifstream reader( fileName );
    
    if(! reader)
    {
        cout << "Code file failed to import." << endl;
        
    }
    else
    {
        while(getline(reader, line))
        {
            cout << line << endl;
            store[i] = line;
            i++;
        }
    }

    reader.close();
}

//fetches an instruction from the store.
Line fetch() 
{

    controlInstruction++;
    string codeLine = store[controlInstruction];
    
    Line newLine(codeLine);

    cout << endl << newLine.getInstruction() << endl;
    cout << newLine.getOperand() << endl;

    return newLine;
}

//decodes the fetched instruction.
int decode(Line &newLine)
{
    
   
    if(newLine.getInstruction() == "0000")
    {
        presentInstruction = "00000000000000000000000000000000";
        cout << "JMP" << endl;
        return 0;
    }
    else if(newLine.getInstruction() == "1000")
    {
        presentInstruction = "10000000000000000000000000000000";
        cout << "JRP" << endl;
        return 1;
    }
    else if(newLine.getInstruction() == "0100")
    {
        presentInstruction = "01000000000000000000000000000000";
        cout << "LDN" << endl;
        return 2;
    }
    else if(newLine.getInstruction() == "1100")
    {
        presentInstruction = "11000000000000000000000000000000";
        cout << "STO" << endl;
        return 3;
    }
    else if(newLine.getInstruction() == "0010")
    {
        presentInstruction = "00100000000000000000000000000000";
        cout << "SUB" << endl;
        return 4;
    }
    else if(newLine.getInstruction() == "1010")
    {
        presentInstruction = "10100000000000000000000000000000";
        cout << "SUB" << endl;
        return 5;
    }
    else if(newLine.getInstruction() == "0110")
    {
        presentInstruction = "01100000000000000000000000000000";
        cout << "CMP" << endl;
        return 6;
    }
    else if(newLine.getInstruction() == "1110")
    {
        presentInstruction = "11100000000000000000000000000000";
        cout << "STP" << endl;
        return 7;
    }
    else if(newLine.getInstruction() == "0001")
    {
        //added instruction, A = S
        cout << "LDS" << endl;
        return 8;
    }
    else if(newLine.getInstruction() == "1001")
    {   
        //added instruction, A + S
        cout << "ADD" << endl;
        return 9;
    }
    else
    {
        cout << "Invalid instruction." << endl;
        return -1;
    }
}

//executes the decoded instruction.
void execute(int instruction, Line &codeLine)
{
    //turning the operand binary into decimal
    int operand = decimalConverter(codeLine.getOperand());
    
    //turning the store position into decimal 
    int position = decimalConverter(store[operand]);
    
    //declaring toStore variable for the STO instruction.
    string toStore;

    switch (instruction)
    {
    case 0:
        //set Contents of control Instruction to content of Store location
        controlInstruction = position;
        break;
    case 1:
         //Add content of store location to contents of control instruction
         controlInstruction = controlInstruction + position;
        break;
    case 2:
         //Load accumulator with negative from store content
         accumulator = -position;
        break;
    case 3:
         //Copy accumulator to store location
         toStore = binaryConverter(accumulator);
         store[operand] = toStore;
        break;
    case 4:
         // Subtract content of store location from accumulator
         accumulator = accumulator - position;
        break;
    case 5:
         // Subtract content of store location from accumulator
         accumulator = accumulator - position;
        break;
    case 6:
         // Increment CI if accumulator value negative, otherwise do nothing
         if(accumulator < 0){
             controlInstruction++;
         }
        break;
    case 7:
        // Set stop lamp to halt machine
        stp = true;
        break;
    case 8:
        //A = S
        accumulator = position;
        break;
    case 9:
        // A = A + S
        accumulator = accumulator + position;
        break;
    default:
        cout << "Invalid instruction." << endl;
        break;
    }

}

//function to convert a binary string to a decimal integer. Used to help with the execute function.
int decimalConverter(string binary){

    bool flipSign = false;
    string toConvert = binary.substr(0,30);
    if(binary[binary.length() - 1] == '1'){

        flipSign = true;
    }

    reverse(toConvert.begin(), toConvert.end());
    int dec = stoi(toConvert, nullptr, 2);


    if(flipSign == true){
        dec = -dec;

    }

    return dec;
}

//converts a decimal integer to a binary string. Used to help with the execute function.
//code for the function adapted from https://stackoverflow.com/q/22746429
string binaryConverter(int n)
{
    string r;

    long decimal = abs(n);
    long val;
    int i = 0;
    while (i < 32)
    {
        val = decimal % 2;
        decimal = decimal/2;

        if(i < 32-1){
            if (val == 0){

                r += "0";

            }else if (val == 1){

                r += "1";

            }
        } else {
            if (n < 0){
                r += "1";
            }else{
                r += "0";
            }
        }
        i++;
    }
    
   
    return r;
}

//display the contents of the registers and memory.
void display()
{
    string aOutput = binaryConverter(accumulator);
    string ciOutput = binaryConverter(controlInstruction);
    cout << "Accumulator:" << aOutput << endl;
    cout << "Control Instruction: " << ciOutput << endl;
    cout << "Present Instruction: " << presentInstruction << endl;
    displayStore();
    
}

//display the contents of the store.
void displayStore()
{
    for (int i = 0; i < 32; i++)
    {
        cout << store[i] << endl;
    }
    
}

//initialise the store.
void initStore(){

     for(int i = 0; i < 32; i++)
    {
        store[i] = "00000000000000000000000000000000";
    }
}

//runs the simulator.
int run()
{    
    int instruction;
    Line codeLine;
    while (!stp)
    
    {
        codeLine = fetch();
        instruction = decode(codeLine);
        execute(instruction, codeLine);
        display();
    }    
    return 0;
}