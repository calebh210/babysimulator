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


int accumulator = 0;
int controlInstruction = 0;
string presentInstruction = "00000000000000000000000000000000";
string store[32]; //load file into store, then work from there.
bool stp = false;




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
            //codeLine++;
        }
    }

    reader.close();
}

Line fetch() 
{

    controlInstruction++;
    string codeLine = store[controlInstruction];
    
    Line newLine(codeLine);

    cout << endl << newLine.getInstruction() << endl;
    cout << newLine.getOperand() << endl;

    return newLine;
    //decode(codeLine);
    
}

int decode(Line &newLine)
//int decode()
{
    
   
    if(newLine.getInstruction() == "000")
    {
        cout << "JMP" << endl;
        return 0;
    }
    else if(newLine.getInstruction() == "100")
    {
        cout << "JRP" << endl;
        return 1;
    }
    else if(newLine.getInstruction() == "010")
    {
        cout << "LDN" << endl;
        return 2;
    }
    else if(newLine.getInstruction() == "110")
    {
        cout << "STO" << endl;
        return 3;
    }
    else if(newLine.getInstruction() == "001")
    {
        cout << "SUB" << endl;
        return 4;
    }
    else if(newLine.getInstruction() == "101")
    {
        cout << "SUB" << endl;
        return 5;
    }
    else if(newLine.getInstruction() == "011")
    {
        cout << "CMP" << endl;
        return 6;
    }
    else if(newLine.getInstruction() == "111")
    {
        cout << "STP" << endl;
        return 7;
    }
    else
    {
        cout << "Invalid instruction." << endl;
        return -1;
    }
}

void execute(int instruction, Line &codeLine)
{
    //turning the operand binary into decimal
    int operand = decimalConverter(codeLine.getOperand());
    cout << "Operand: " << operand << endl;
    //turning the store position into decimal 
    int position = decimalConverter(store[operand]);
    cout << "Position: " << position << endl;
    //declaring toStore variable for the STO instruction.
    string toStore;
    //CI= contents of control instruction
    //A= contents of accumulator
    switch (instruction)
    {
    case 0:
        //JMP
        //CI = S
        //set Contents of control Instruction to content of Store location
        controlInstruction = position;
        break;
    case 1:
         //JRP
         // CI = CI+S
         //Add content of store location to contents of control instruction
         controlInstruction = controlInstruction + position;
        break;
    case 2:
         //LDN
         //A = -S
         //Load accumulator with negative from store content
         accumulator = -position;
        break;
    case 3:
        //STO
         //S=A
         //Copy accumulator to store location
         //cout << endl << "Accumulator test " << accumulator << endl;
         toStore = binaryConverter(accumulator);
         store[operand] = toStore;
        break;
    case 4:
        //SUB
         // A = A-S
         // Subtract content of store location from accumulator
         accumulator = accumulator - position;
        break;
    case 5:
         //SUB
         // A = A-S
         // Subtract content of store location from accumulator
         accumulator = accumulator - position;
        break;
    case 6:
         //CMP
         // if A<0 then CI= CI+1
         // Increment CI if accumulator value negative, otherwise do nothing
         if(accumulator < 0){
             controlInstruction++;
         }
        break;
    case 7:
        //STP
        // stop
        // Set stop lamp to halt machine
        stp = true;
        break;
    default:
        cout << "Invalid instruction." << endl;
        break;
    }

}

int decimalConverter(string operandCode){

    reverse(operandCode.begin(), operandCode.end());
    int operand = stoi(operandCode, nullptr, 2);
    return operand;
}

//code for the following function adapted from https://stackoverflow.com/q/22746429
string binaryConverter(int n)
{
    string r;
    //cout << "converter entered" << endl;
    if (n == 0)
    {
        //cout << "returning 0" << endl;
        return "0";
    }

    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    //cout << "binary test: " << r << endl;
    reverse(r.begin(), r.end());
    //cout << "Reversed: " << r << endl;
    return r;
}

void display()
{
    cout << "Accumulator:" << accumulator << endl;
    cout << "Control Instruction: " << controlInstruction << endl;
    
}

void displayStore()
{
    for (int i = 0; i < 32; i++)
    {
        cout << store[i] << endl;
    }
    
}

void initStore(){

     for(int i = 0; i < 32; i++)
    {
        store[i] = "00000000000000000000000000000000";
    }
}


int run()
{
    /*int test = 1646;
    string test1result = binaryConverter(test);
    cout << "Testing binary converter: " << test1result << endl;*/

    //cout << "store test:" << endl << "Position 0: " << store[0] << endl << "Position 5: " << store[5] << endl << "Position 8: " << store[8] << endl << "Position 16: " << store[16] << endl << "Position 31: " << store[31] << endl << "Position 32 (out of range): " << store[32] << endl;

    //cout << "store test:" << endl << "Position 0: " << store[0] << endl << "Position 5: " << store[5] << endl << "Position 8: " << store[8] << endl << "Position 16: " << store[16] << endl << "Position 31: " << store[31] << endl << "Position 32 (out of range): " << store[32] << endl;
    
    int instruction;
    //cout << "instruction created" << endl;
    Line codeLine;
    //cout << "Line created" << endl;
    while (!stp)
    
    {
        //cout << "loop entered" << endl;
        //fetch();
        codeLine = fetch();
        //cout << "fetch completed" << endl;
        instruction = decode(codeLine);
        //cout << "decode completed" << endl;

        //fetch();
        //instruction = decode();
        execute(instruction, codeLine);
        //cout << "execute completed" << endl;
        display();
        //cout << "display completed" << endl;
    }
    //cout << "loop exited" << endl;
    // displayStore();
    return 0;
}