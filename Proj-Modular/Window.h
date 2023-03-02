#include <iostream>
using namespace std;

class Window
{
protected:
    string name;
    int width, height;

public:
    Window(string n, int w, int h) : name(n), width(w), height(h) { cout << "Window(string, int, int) constructor run.." << endl; }
    void showMemeber();
    int getArea();
};