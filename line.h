//Group 10: Caleb Harmon, Daniel Nagy, Jerry Deligiannis, Lewis McLean, Luca Zen, & Sandy Steuart Fothringham
//Simulator Team: Caleb Harmon, Luca Zen, Sandy Steuart Fothringham
//File Authors: Caleb Harmon, Luca Zen

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//definitions for the Line class.
class Line
{
private:
   string instruction;
   string operand;
public:
    Line();
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

//function definitions for the Line class.
Line::Line()
{
    instruction = "";
    operand = "";
}

Line::Line(string code)
{
    instruction = code.substr(13, 4);
    operand = code.substr(0, 5);
}

Line::~Line()
{
}