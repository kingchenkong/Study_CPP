#include <iostream>
#include <cstdlib>
using namespace std;

// function declaration
void functionNameLog(string);
void consoleValue(int, int, string);
void consolePointer(int &, int &, string);

int add10ByValue(int);
int add10ByPointer(int *);
int add10ByReference(int &);

int main(void)
{
    int valueInput = 123;
    int valueOutput = 0;
    int *pointerInput = &valueInput;
    int *pointerOutput = &valueOutput;

    cout << "vIn = " << valueInput << ", &vIn = " << &valueInput << endl;
    cout << "pIn = " << pointerInput << ", *pIn = " << *pointerInput << ", &pIn = " << &pointerInput << endl;

    cout << "vOut = " << valueOutput << ", &vOut = " << &valueOutput << endl;
    cout << "pOut = " << pointerOutput << ", *pOut = " << *pointerOutput << ", &pOut = " << &pointerOutput << endl;

    consoleValue(valueInput, valueOutput, "initial state");

    // call by Value
    valueOutput = add10ByValue(valueInput);
    consoleValue(valueInput, valueOutput, "add10ByValue");

    // call by Pointer
    valueOutput = add10ByPointer(&valueInput);
    consoleValue(valueInput, valueOutput, "add10ByPointer");

    // call by Reference
    valueOutput = add10ByReference(valueInput);
    consoleValue(valueInput, valueOutput, "add10ByReference");

    // console the pointer
    cout << "valueInput pointer: " << &valueInput << endl;
    cout << "valueOutput pointer: " << &valueOutput << endl;
    // cout << "valueInput pointer: " << *valueInput << endl; // that is wrong.

    consolePointer(valueInput, valueOutput, "console pointer");

    system("pause");
    return 0;
}

// function implementation
void functionNameLog(string funcName)
{
    cout << "func: " << funcName << " | ";
    return;
}

void consoleValue(int input, int output, string tag)
{
    functionNameLog(tag);
    cout << "input: " << input << ", output: " << output << endl;
    return;
}

void consolePointer(int &val1, int &val2, string tag)
{
    functionNameLog(tag);
    // '&' use to get the address
    // '*' tag a variable, it use to save the address
    int *pointer1 = &val1;
    int *pointer2 = &val2;
    cout << "pointer1: " << pointer1 << ", pointer2: " << pointer2 << endl;
    return;
}

int add10ByValue(int value)
{
    return value + 10;
}

int add10ByPointer(int *value)
{
    *value += 10;
    return *value;
}

int add10ByReference(int &value)
{
    value += 10;
    return value;
}