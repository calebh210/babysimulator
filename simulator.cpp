#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int fileLine = 0;

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

string fetch()
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
            reader.close();
            return line;
        }
    }
}

int decode()
{
    //string codeLine = "10010000000001100000000000000000";
    string codeLine = fetch();
    string instruction = codeLine.substr(13, 3);
    string operand = codeLine.substr(0, 5);
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
    do
    {
        fetch();
        decode();
        execute();
        display();
    }while(decode() != 7);
    return 0;
}