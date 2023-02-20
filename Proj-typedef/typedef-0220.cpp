#include <iostream>
#include <cstdlib>

using namespace std;

// declarationsu
typedef struct
{
    int hour;
    int min;
    float sec;
} myTime;
void consoleDivider();
void consoleTime(int, int, int);

int main(void)
{
    typedef int clock;
    clock hour = 3, minute = 19, second = 46;
    consoleTime(hour, minute, second);
    consoleDivider();

    myTime time[3] = {
        {1, 16, 11},
        {14, 28, 59},
        {23, 32, 46}};
    for (size_t i = 0; i < 3; i++)
    {
        cout << "i = " << i << endl;
        consoleTime(time[i].hour, time[i].min, time[i].sec);
    }
    consoleDivider();

    system("pause");
    return 0;
}

// implements
void consoleDivider()
{
    cout << " - - - - - - - - - - - - - - - - - - - - " << endl;
}

void consoleTime(int h, int m, int s)
{
    cout << "hour: " << h << endl;
    cout << "minute: " << m << endl;
    cout << "second: " << s << endl;
}
