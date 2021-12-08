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
//Line newLine;

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

Line fetch() //try loading file into store. fetch from there rather
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

    //cout << "fetch entered" << endl;
    Line newLine;
    //cout << "newLine created" << endl;

    position++;
    //cout << "position incremented" << endl;
    string codeLine = store[position];
    //cout << "codeLine loaded" << endl;

    string instruction = codeLine.substr(13, 3);
    //cout << "instruction found" << endl;
    string operand = codeLine.substr(0, 5);
    //cout << "operand found" << endl;
    newLine.setOperand(operand);
    //cout << "operand set" << endl;
    newLine.setInstruction(instruction);
    //cout << "instruction set" << endl;
    cout << endl << newLine.getInstruction() << endl;
    cout << newLine.getOperand() << endl;

    return newLine;
    //decode(codeLine);
    
}

int decode(Line &newLine)
//int decode()
{
    //string codeLine = "10010000000001100000000000000000";
    //Line newLine(codeLine);
    //Line newLine(line);
   
    //string codeLine = fetch();
    /*string instruction = line.substr(13, 3);
    string operand = line.substr(0, 5);
    newLine.setOperand(operand);
    newLine.setInstruction(instruction);
    cout << endl << newLine.getInstruction() << endl;
    cout << newLine.getOperand() << endl;*/
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
    if (instruction == 0)
    {
        //JMP
        // CI = S
        //set Contents of control Instruction to content of Store location
    }
    else if (instruction == 1)
    {
         //JRP
         // CI = CI+S
         //Add content of store location to contents of control instruction
    }
    else if (instruction == 2)
    {
         //LDN
         //A = -S
         //Load accumulator with negative from store content
    }
    else if (instruction == 3)
    {
         //STO
         //S=A
         //Copy accumulator to store location
    }
    else if (instruction == 4)
    {
         //SUB
         // A = A-S
         // Subtract content of store location from accumulator
    }
    else if (instruction == 5)
    {
         //SUB
         // A = A-S
         // Subtract content of store location from accumulator
    }
    else if (instruction == 6)
    {
         //CMP
         // if A<0 then CI= CI+1
         // Increment CI if accumulator value negative, otherwise do nothing
    }
    else if (instruction == 7)
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
    /*for(int i = 0; i < 32; i++)
    {
        store[i] = "00000000000000000000000000000000";
    }
    cout << "store test:" << endl << "Position 0: " << store[0] << endl << "Position 5: " << store[5] << endl << "Position 8: " << store[8] << endl << "Position 16: " << store[16] << endl << "Position 31: " << store[31] << endl << "Position 32 (out of range): " << store[32] << endl;*/

    loadFromFile();
    //cout << "store test:" << endl << "Position 0: " << store[0] << endl << "Position 5: " << store[5] << endl << "Position 8: " << store[8] << endl << "Position 16: " << store[16] << endl << "Position 31: " << store[31] << endl << "Position 32 (out of range): " << store[32] << endl;
    
    int instruction;
    //cout << "instruction created" << endl;
    Line codeLine;
    //cout << "Line created" << endl;
    do
    {
        //cout << "loop entered" << endl;
        //fetch();
        codeLine = fetch();
        //cout << "fetch completed" << endl;
        instruction = decode(codeLine);
        //cout << "decode completed" << endl;

        //fetch();
        //instruction = decode();
        execute(instruction);
        //cout << "execute completed" << endl;
        display();
        //cout << "display completed" << endl;
    }while(instruction != 7);
    //cout << "loop exited" << endl;
    return 0;
}