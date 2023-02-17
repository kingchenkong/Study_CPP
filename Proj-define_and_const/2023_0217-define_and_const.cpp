#include <iostream>
#include <cstdlib>
using namespace std;

// define
#define MAX_UNSIGNED_INT = 4294967295
#define MAX_UNSIGNED_SHORT_INT = 65535
#define PI = 3.14159
#define STRING_HELLO = "Hello World!!"
/* #define FUNC_POWER i *i *i => will 'syntax error', cause i is not declared
    the #define is set "i *i *i" swap the 'code' when the compiler
    Here num is exist, but i not exist, so error. */
#define FUNC_POWER num *num *num
#define FUNC_POWER_2(X) X *X *X
#define FUNC_POWER_3(X) (X) * (X) * (X)

const int const_int_outta = 2;

// function declaration
void functionCall();
void functionNameLog(string);
void executeDefineFunc();
void consoleConst();

int main(void)
{
    const char const_char_main = 'a';
    functionCall();
    system("pause");
    return 0;
}

// function implementation
void functionCall()
{
    executeDefineFunc();
    consoleConst();

    return;
}

void functionNameLog(string funcName)
{
    cout << "func: " << funcName << " | ";
    return;
}

void executeDefineFunc()
{
    // num
    int num = 2;
    cout << "num = " << num << endl;

    functionNameLog("FUNC_POWER");
    int power1 = FUNC_POWER;
    cout << "power1 = " << power1 << endl;

    functionNameLog("FUNC_POWER_2");
    int power2 = FUNC_POWER_2(num);
    cout << "power2 = " << power2 << endl;

    // num +1
    cout << "num+1 = " << num + 1 << endl;

    functionNameLog("FUNC_POWER_2");
    int power2Add1 = FUNC_POWER_2(num + 1);
    cout << "power2Add1 = " << power2Add1 << endl;
    /* FUNC_POWER_2 | power2Add1 = 7
        cause num = 2, num + 1 = 3

        "FUNC_POWER_2(X) X *X *X"
            will change to =>
        "FUNC_POWER_2(num+1) num + 1 * num + 1 * num + 1"
            = 2 + 1*2 + 1*2 + 1
            = 6 + 1
            = 7
         */

    functionNameLog("FUNC_POWER_3");
    int power3Add1 = FUNC_POWER_3(num + 1);
    cout << "power3Add1 = " << power3Add1 << endl;

    return;
}

void consoleConst()
{
    functionNameLog("consoleConst");
    cout << "const_int_outta: " << const_int_outta << endl;
    // cout << "const_char_main: " << const_char_main << endl;
    // cannot call it.
    
    // const_int_outta += 1;
    // const variable cannot modify.

    return;
}
