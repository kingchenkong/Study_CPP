#include <iostream>
#include <cstdlib>

using namespace std;

// template class: declarations
// template <class S, class NUM, char id /* input static type; cannot use: float, double, string */>
template <class S, class NUM>
class Window
{
protected:
    S name;
    NUM width, height;
    double red, green, blue;

public:
    Window(S n, NUM w, NUM h) : name(n), width(w), height(h), red(0.0), green(0.0), blue(0.0) { cout << "Window(), construct.." << endl; }
    Window(S n, NUM w, NUM h, double r, double g, double b) : name(n), width(w), height(h), red(r), green(g), blue(b) { cout << "Window(), construct.." << endl; }

    void showMember();
    NUM area() { return width * height; }
};
// template <class S, class NUM, char id>
// void Window<S, NUM, id>::showMember()

template <class S, class NUM>
void Window<S, NUM>::showMember()
{
    // cout << "-- Window, name: " << name << ", width: " << width << ", height: " << height << ", id: " << id << endl;
    cout << "-- Window, name: " << name << ", width: " << width << ", height: " << height << endl;
    cout << "---------- red: " << red << ", green: " << green << ", blue: " << blue << endl;
    cout << "---------- area: " << area() << endl;
}

// template class: specialized
template <>
class Window<string, double>
// class Window<string, double, '-'>
{
protected:
    string name;
    double width, height;

public:
    Window(string n, double w, double h) : name(n), width(w), height(h) { cout << "Window() specialized, construct.." << endl; }

    void showMember()
    {
        cout << "-- Window, name: " << name << ", width: " << width << ", height: " << height << endl;
        cout << "---------- area: " << area() << endl;
    }
    double area() { return 0.0; }
};
// template <>
// void Window<string, double>::showMember()
// {
//     cout << "-- Window, name: " << name << ", width: " << width << ", height: " << height << endl;
//     cout << "---------- area: " << area() << endl;
// }

template <>
short Window<string, short>::area()
{
    return -1;
}

// template function: declarations
template <class T>
T add(T a, T b);
template <class T, class R>
double average(T val1, R val2);

// field
// Window<string, int, 'A'> *win1;
// Window<string, int, 'B'> *win2;
// Window<string, double, 'd'> *winSp1;
Window<string, int> *win1;
Window<string, int> *win2;
Window<string, double> *winSp1;
Window<string, short> *winSp2;

int main()
{
    cout << "#### template - add" << endl;
    cout << "<int>,    add(3,5)=          " << add<int>(3, 5) << endl;
    cout << "<int>,    add(9,6)=          " << add(9, 6) << endl;
    cout << "<double>, add(3.14159,2.33)= " << add<double>(3.14159, 2.33) << endl;
    cout << "<string>, add(ok~, hohoho~)= " << add<string>("ok", "hohoho~") << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "#### template - average" << endl;
    cout << "<int,int>,    average(99,70)=      " << average(99, 70) << endl;
    cout << "<int,double>, average(8,12.3)=     " << average<int, double>(8, 12.3) << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "#### template - class: Window" << endl;
    // win1 = new Window<string, int, 'A'>("win1", 5, 6);
    win1 = new Window<string, int>("win1", 5, 6);
    win1->showMember();
    // win2 = new Window<string, int, 'B'>("win2", 7, 8, 0.5, 0.3, 0.2);
    win2 = new Window<string, int>("win2", 7, 8, 0.5, 0.3, 0.2);
    win2->showMember();
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "#### template - class: Window Specialize" << endl;
    // winSp1 = new Window<string, double, 'd'>("winSp1", 3.0, 5.0);
    winSp1 = new Window<string, double>("winSp1", 3.0, 5.0);
    winSp1->showMember();
    short w = 3, h = 9;
    winSp2 = new Window<string, short>("winSp2", w, h);
    winSp2->showMember();
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "#################################### End ####################################" << endl;
    delete win1;
    delete win2;
    delete winSp1;
    delete winSp2;
    win1 = NULL;
    win2 = NULL;
    winSp1 = NULL;
    winSp2 = NULL;
    system("pause");
    return 0;
}

// template function: implements
template <class T>
T add(T a, T b) { return a + b; }

template <class T, class R>
double average(T val1, R val2) { return (double)(val1 + val2) / 2; }
