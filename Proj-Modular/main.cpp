#include <iostream>
#include <cstdlib>

#include "Window.h"

using namespace std;

Window *ptrWin1 = NULL;

int main()
{
    cout << "################## start ##################" << endl;

    ptrWin1 = new Window("ptrWin1", 8, 12);
    ptrWin1->showMemeber();

    cout << "################## end ##################" << endl;
    delete ptrWin1;
    ptrWin1 = NULL;
    system("pause");
    return 0;
}
