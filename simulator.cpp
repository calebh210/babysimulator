#include<iostream>
#include<fstream>
#include<string>
#include "line.h"
using namespace std;

int position = 0;

int accumulator = 00000000000000000000000000000000;
int currentInstruction = 00000000000000000000000000000000;
int presentInstruction = 00000000000000000000000000000000;
string store[32]; //load file into store, then work from there.

int decode(string line);

void loadFromFile()
{
    string line;
    int i = 0;

    ifstream reader( "BabyTest1-MC.txt" );

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

void fetch() //try loading file into store. fetch from there rather
            //than straight from file.
{
    /*string line;
    ifstream reader( "BabyTest1-MC.txt" );

    if(! reader)
    {
        cout << "Code file failed to import." << endl;
        reader.close();
    }
    else
    {
        while(getline(reader, line))
        {
            fileLine++;
            cout << line << endl;
            decode(line);
            //reader.close();
            //return line;
        }
    }

    reader.close();*/

    position++;
    string codeLine = store[position];
    decode(codeLine);
    
}

int decode(string line)
{
    string codeLine = "10010000000001100000000000000000";
    Line newLine(codeLine);
   
    //string codeLine = fetch();
    string instruction = line.substr(13, 3);
    string operand = line.substr(0, 5);
    newLine.setOperand(operand);
    newLine.setInstruction(instruction);
    cout << endl << newLine.getInstruction() << endl;
    cout << newLine.getOperand() << endl;
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

void execute(int instruction)
{

    //S = contents of that store location
    //CI= contents of control instruction
    //A= contents of accumulator
    if (newLine.getInstruction() == "000")
    {
        //JMP
        // CI = S
        //set Contents of control Instruction to content of Store location
    }
    else if (newLine.getInstruction() == "100")
    {
         //JRP
         // CI = CI+S
         //Add content of store location to contents of control instruction
    }
    else if (newLine.getInstruction() == "010")
    {
         //LDN
         //A = -S
         //Load accumulator with negative from store content
    }
    else if (newLine.getInstruction() == "110")
    {
         //STO
         //S=A
         //Copy accumulator to store location
    }
    else if (newLine.getInstruction() == "001")
    {
         //SUB
         // A = A-S
         // Subtract content of store location from accumulator
    }
    else if (newLine.getInstruction() == "101")
    {
         //SUB
         // A = A-S
         // Subtract content of store location from accumulator
    }
    else if (newLine.getInstruction() == "011")
    {
         //CMP
         // if A<0 then CI= CI+1
         // Increment CI if accumulator value negative, otherwise do nothing
    }
    else if (newLine.getInstruction() == "111")
    {
        //STP
        // stop
        // Set stop lamp to halt machine
    }
    else
    {
        cout << "Invalid instruction." << endl;
        
    }
}

void display()
{
    //int toDisplay = decode();
    //cout << "Result: " << toDisplay << endl;
}

int main()
{
    for(int i = 0; i < 32; i++)
    {
        store[i] = "00000000000000000000000000000000";
    }
    cout << "store test:" << endl << "Position 0: " << store[0] << endl << "Position 5: " << store[5] << endl << "Position 8: " << store[8] << endl << "Position 16: " << store[16] << endl << "Position 31: " << store[31] << endl << "Position 32 (out of range): " << store[32] << endl;

    loadFromFile();
    cout << "store test:" << endl << "Position 0: " << store[0] << endl << "Position 5: " << store[5] << endl << "Position 8: " << store[8] << endl << "Position 16: " << store[16] << endl << "Position 31: " << store[31] << endl << "Position 32 (out of range): " << store[32] << endl;

    //do
    //{
        fetch();
        // decode();
        //execute();
        display();
    //}while(decode() != 7);
    return 0;
}