#include <iostream>
#include <cstdlib>

using namespace std;

// declaration: class
// - super
class Window
{
protected:
    string name;
    int width, height;

public:
    Window(string n, int w, int h) : name(n), width(w), height(h) { cout << " Window(n, w, h), is called.." << endl; }
    ~Window()
    {
        cout << "~Window(), " << endl;
        showMember();
    }
    void showMember() { cout << "Window, \"" << name << "\", w: " << width << ", h: " << height << endl; }
    void showArea() { cout << "Window, \"" << name << "\", area= " << area() << endl; }
    virtual int area()
    {
        cout << "Window->area(): ";
        return width * height;
    }
    static void destroy(Window *ptr);
    static void showAddress(Window *ptr);
};
void Window::destroy(Window *ptr)
{
    if (ptr != NULL)
    {
        delete ptr; // Free memory allocated for the a array.
        ptr = NULL; // Be sure the deallocated memory isn't used.
    }
}
void Window::showAddress(Window *ptr) { cout << "address: " << &ptr << endl; }

// - child
class ChildWindow : public Window
{
public:
    ChildWindow(string n, int w, int h) : Window(n, w, h) { cout << " ChildWindow(n, w, h), is called.." << endl; }
    ~ChildWindow()
    {
        cout << "~ChildWindow(), " << endl;
        showMember();
    }
    int area()
    {
        cout << "ChildWindow->area(): ";
        return Window::area() * 0.8;
    }
    static void destroy(ChildWindow *ptr);
};
void ChildWindow::destroy(ChildWindow *ptr)
{
    if (ptr != NULL)
    {
        delete ptr;
        ptr = NULL;
    }
}
// declaration: funciton
void consoleDivider();
void destroy();

// declaration: field variables, hint: must initialize...
Window *ptrWindow1 = NULL;
ChildWindow *ptrChildWindow1 = NULL;
Window *ptrContainerWindow = NULL;

// main
int main()
{
    string n1 = "ptrWindow1";
    cout << "#### " << n1 << endl;
    ptrWindow1 = new Window(n1, 2, 3);
    ptrWindow1->showMember();
    ptrWindow1->showArea();

    string n2 = "ptrChildWindow1";
    cout << "#### " << n2 << endl;
    ptrChildWindow1 = new ChildWindow(n2, 5, 6);
    ptrChildWindow1->showMember();
    ptrChildWindow1->showArea();
    consoleDivider();

    string n3 = "ptrContainerWindow";
    cout << "#### " << n3 << ", pointer Window." << endl;
    ptrContainerWindow = new Window(n3, 7, 8);
    ptrContainerWindow->showMember();
    ptrContainerWindow->showArea();
    Window::showAddress(ptrContainerWindow);
    Window::destroy(ptrContainerWindow);
    Window::showAddress(ptrContainerWindow);
    cout << "#### " << n3 << ", pointer ChildWindow." << endl;
    ptrContainerWindow = new ChildWindow(n3, 9, 10);
    ptrContainerWindow->showMember();
    ptrContainerWindow->showArea();
    Window::showAddress(ptrContainerWindow);
    ChildWindow::destroy((ChildWindow *)ptrContainerWindow);
    Window::showAddress(ptrContainerWindow);
    consoleDivider();

    cout << "#### end - destroy ####" << endl;
    destroy();
    consoleDivider();

    system("pause");
    return 0;
}

// implements: funciton
void consoleDivider() { cout << "--------------------------------" << endl; }
void destroy()
{
    Window::destroy(ptrWindow1);
    Window::destroy(ptrChildWindow1);
    Window::destroy(ptrContainerWindow);
}
