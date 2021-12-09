#include <string>
using namespace std;

//decodes the instruction
int decode(string line);


//converts the string binary operand to decimal
int decimalConverter(string operandCode);

//converts a decimal integer to a binary string
string binaryConverter(int toConvert);

//alternative binary converter
string toBinary(int n);

//displays some useful values
void display();