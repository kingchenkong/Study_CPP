#include <iostream>
#include <cstdlib>
// #include <vector>

using namespace std;

// declarations
struct StudentData
{
    string name;
    int number;
};
void conosleStudent(StudentData);
void conosleDivider();

// implements
void conosleDivider()
{
    cout << " - - - - - - - - - - - - - - - - - - - - " << endl;
}

void consoleStudent(StudentData data)
{
    cout << "student:" << endl;
    cout << " name: " << data.name << ",";
    cout << " number: " << data.number << endl;
}

// main
int main(void)
{
    struct StudentData student = {"Lily Chen", 25};
    struct StudentData student2 = {"Mike Wang", 19};

    consoleStudent(student);
    consoleStudent(student2);
    conosleDivider();

    system("pause");
    return 0;
}
