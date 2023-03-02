#include "Window.h"
#include <iostream>
using namespace std;

void Window::showMemeber() { cout << "name: " << name << ", width: " << width << ", height: " << height << ", area()= " << getArea() << endl; }

int Window::getArea() { return width * height; }