#include <iostream>
#include <cstdlib>
// #include <array>
#include <vector>

using namespace std;

// function declarations
void functionNameLog(string);
void consoleDivider();
void consoleArraySize(int *);
void consoleArrayElements(int *);
int getArrayLength(int *);

int getVectorLength(vector<int>);

int main(void)
{
    int intArr[10] = {109, 202, 303, 404, 505, 606, 707, 808, 909, 1000};
    // cout << "intArr:                " << endl;
    // cout << "size of address:       " << sizeof(&intArr) << endl;
    // cout << "intArr[0]:             " << intArr[0] << endl;
    // cout << "memory size of int:    " << sizeof(int) << endl;
    // cout << "memory size of array:  " << sizeof(intArr) << endl;
    // cout << "lenght of array:       " << sizeof(intArr) / sizeof(intArr[0]) << endl;
    // cout << "lenght2 of array:      " << *(&intArr + 1) - intArr << endl;
    // cout << "lenght3 of array:      " << &intArr[10] - intArr << endl;
    // consoleDivider();
    // cout << "intArr address:            " << intArr << endl;
    // cout << "next address: (&array + 1) " << (&intArr + 1) << endl;
    // cout << "intArr[10] address:        " << &intArr[10] << endl;

    consoleDivider();
    // consoleArraySize(array1);

    int arrayLen = getArrayLength(intArr);
    consoleDivider();

    vector<int> vec1 = {1, 23, 345, 6789, 11, 2323, 345345};
    cout << "vec len: " << vec1.size() << endl;
    cout << "vec len: " << getVectorLength(vec1) << endl;

    system("pause");
    return 0;
}

// function implements

int getVectorLength(vector<int> vec)
{
    functionNameLog("getVectorLength");
    int len = vec.size();
    cout << "vec: length: " << len << endl;
    // cout << "vec: length: " << len << endl;
    return len;
}

int getArrayLength(int *array)
{
    functionNameLog("getArrayLength");

    cout << "array:                 " << array << endl;
    cout << "size of address:       " << sizeof(&array) << endl;
    cout << "memory size of int:    " << sizeof(int) << endl;
    cout << "memory size of array:  " << sizeof(*array) << endl;
    cout << "lenght of array:       " << sizeof(array) / sizeof(int) << endl;
    consoleDivider();

    cout << "array address:         " << array << endl;
    cout << "intArr[10] address:    " << &array[10] << ", sub: " << &array[10] - array << endl;
    cout << "(&array + 1)           " << (&array + 1) << ", sub: " << (&array + 1) - &array << endl;
    cout << "array + 1              " << array + 1 << endl;
    // cout << "array + 1              " << end(array) << endl;

    consoleDivider();

    // int *address = array;
    // int *nextAddress = *(&array + 1);
    // int result = nextAddress - address;

    // cout << "array | address: " << address << ", nextAddress: " << nextAddress << ", result: " << result << endl;

    // int len = *(&array + 1) - array;
    // cout << "len: " << len << endl;

    // for (size_t i = 0; i < 10; i++)
    // {
    //     cout << "array[" << i << "] = " << array[i] << endl;
    // }

    return 0;
}

void consoleArraySize(int *array)
{
    int sizeOfElements = sizeof(array[0]);
    int sizeOfArray = sizeof(array);
    int length = sizeOfArray / sizeOfElements;

    cout << "size of elements: " << sizeOfElements;
    cout << ", size of array: " << sizeOfArray;
    cout << ", length of array: " << length << endl;
    return;
}

void consoleArrayElements(int *array)
{

    return;
}

void consoleDivider()
{
    cout << "- - - - - - - - - - - - - - - - - - - " << endl;
    return;
}

void functionNameLog(string funcName)
{
    cout << funcName << " | " << endl;
    return;
}
