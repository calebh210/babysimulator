//add class for line 
//getter and setter for operand and instructions
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Line
{
private:
   string instruction;
   string operand;
public:
    Line(string code);
    ~Line();

    string getOperand(){
        return operand;
    }

    string getInstruction(){
        return instruction;
    }

    void setOperand(string o){
        operand = o;
    }

    void setInstruction(string i){
        instruction = i;
    }

};

Line::Line(string code)
{
    instruction = code.substr(13, 3);
    operand = code.substr(0, 5);
}

Line::~Line()
{
}
