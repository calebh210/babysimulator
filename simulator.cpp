#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int codeLine = 0;

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
            codeLine++;
            cout << line << endl;
            reader.close();
            return line;
        }
    }
}

void decode()
{
    //string codeLine = "10010000000001100000000000000000";
    string codeLine = fetch();
    string instruction = codeLine.substr(13, 3);
    cout << endl << instruction << endl;
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