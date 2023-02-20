#include <iostream>
#include <cstdlib>
// #include <vector>

using namespace std;

// declarations
struct StudentData
{
    string name;
    int number, scoreMath, scoreEnglish;
};

void conosleStudent(struct StudentData);
void conosleDivider();
void changeNumber(struct StudentData *, int);

// implements
void conosleDivider()
{
    cout << " - - - - - - - - - - - - - - - - - - - - " << endl;
}

void consoleStudent(struct StudentData data)
{
    cout << "student:" << endl;
    cout << " name: " << data.name << ",";
    cout << " number: " << data.number << endl;
    cout << "size of StudentData: " << sizeof(data) << endl;
}

void changeNumber(struct StudentData *data, int newNumber)
{
    data->number = newNumber;
}

// main
int main(void)
{
    struct StudentData student1 = {"Lily Chen", 25, 80, 66};
    struct StudentData student2 = {"Mike Wang", 19};

    consoleStudent(student1);
    consoleStudent(student2);
    conosleDivider();

    changeNumber(&student1, 98);
    changeNumber(&student2, 109);
    consoleStudent(student1);
    consoleStudent(student2);
    conosleDivider();

    system("pause");
    return 0;
}
