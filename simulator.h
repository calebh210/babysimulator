#include <string>
using namespace std;

//decodes the instruction
int decode(string line);


//converts the string binary operand to decimal
int decimalConverter(string operandCode);

//converts a decimal integer to a binary string
string binaryConverter(int n);

//displays some useful values
void display();

//adapted from stackoverflow https://stackoverflow.com/questions/46292764/check-for-file-existence-in-c-without-creating-file
bool exists (const string& fileName) {
    ifstream f(fileName.c_str());
    return f.good();
}