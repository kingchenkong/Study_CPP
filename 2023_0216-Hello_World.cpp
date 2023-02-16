// 2023 0216 - Hello World!
#include <iostream>
#include <cstdlib>
// using namespace std;
int main(void)
{
    std::cout << "Hello world, C++. 2023 0216" << std::endl;

    int year = 2023;
    int month = 02;
    int date = 16;

    std::cout << "Today date is " << year << "/" << month << "/" << date << "" << std::endl;

    std::cout << "Year is " << year;
    std::cout << ", Month is " << month;
    std::cout << ", day is " << date << std::endl;

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
