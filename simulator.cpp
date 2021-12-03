#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int fileLine = 0;

int accumulator;
int currentInstruction;
int presentInstruction;
string store[32];

int decode(string line);

/*void loadFromFile()
{
    string line;
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
            codeLine++;
        }
    }

    reader.close();
}*/

void fetch()
{
    string line;
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

    reader.close();
}

int decode(string line)
{
    //string codeLine = "10010000000001100000000000000000";
    //string codeLine = fetch();
    string instruction = line.substr(13, 3);
    string operand = line.substr(0, 5);
    cout << endl << instruction << endl;
    cout << operand << endl;

    if(instruction == "000")
    {
        cout << "JMP" << endl;
        return 0;
    }
    else if(instruction == "100")
    {
        cout << "JRP" << endl;
        return 1;
    }
    else if(instruction == "010")
    {
        cout << "LDN" << endl;
        return 2;
    }
    else if(instruction == "110")
    {
        cout << "STO" << endl;
        return 3;
    }
    else if(instruction == "001")
    {
        cout << "SUB" << endl;
        return 4;
    }
    else if(instruction == "101")
    {
        cout << "SUB" << endl;
        return 5;
    }
    else if(instruction == "011")
    {
        cout << "CMP" << endl;
        return 6;
    }
    else if(instruction == "111")
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

void execute()
{
    //
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

    //do
    //{
        fetch();
        //decode();
        execute();
        display();
    //}while(decode() != 7);
    return 0;
}