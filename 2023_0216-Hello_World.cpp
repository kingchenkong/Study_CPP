// 2023 0216 - Hello World!
#include <iostream>
#include <cstdlib>
using namespace std;

// function declaration
void functionNameLog(string);
void consoleHello();
void consoleDate1(int, int, int);
void consoleDate2(int, int, int);

int main(void)
{
    // std::cout << "Hello world, C++. 2023 0216" << std::endl;
    consoleHello();

    int year = 2023;
    int month = 02;
    int date = 16;

    // std::cout << "Today date is " << year << "/" << month << "/" << date << "" << std::endl;
    consoleDate1(year, month, date);

    // std::cout << "Year is " << year;
    // std::cout << ", Month is " << month;
    // std::cout << ", day is " << date << std::endl;
    consoleDate2(year, month, date);

    char char_a = 'a';
    int ascii_a = char_a;
    char char_A = 'A';
    int ascii_A = char_A;

    std::cout << char_a << ", ASCII code is " << ascii_a << std::endl;
    std::cout << char_A << ", ASCII code is " << ascii_A << std::endl;

    int inputNumber;
    std::cout << "Input a Number: ";
    std::cin >> inputNumber;
    std::cout << "input is " << inputNumber << std::endl;

    system("pause");
    return 0;
}

// function implementation
void functionNameLog(string funcName)
{
    std::cout << "func: " << funcName << " | ";
    return;
}

void consoleHello()
{
    functionNameLog("consoleHello");
    std::cout << "Hello world, C++. 2023 0216" << std::endl;
    return;
}

void consoleDate1(int y, int m, int d)
{
    functionNameLog("consoleDate1");
    std::cout << "Today date is " << y << "/" << m << "/" << d << "" << std::endl;
    return;
}

void consoleDate2(int y, int m, int d)
{
    functionNameLog("consoleDate2");
    std::cout << "Year is " << y;
    std::cout << ", Month is " << m;
    std::cout << ", day is " << d << std::endl;
    return;
}
