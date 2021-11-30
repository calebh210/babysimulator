#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int codeLine = 0;

void loadFromFile()
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
}

void fetch()
{
    loadFromFile();
}

void decode()
{
    //
}

void execute()
{
    //
}

void display()
{
    //
}

int main()
{
    fetch();
    decode();
    execute();
    display();
    return 0;
}