#include <iostream>
#include <cstdlib>

using namespace std;

// declarations
class Rectangle
{
    // private: // default is private.
    char id;
    int width;
    int height;
    // private memeber function
    int area();
    int perimeter();

public:
    // constructor
    Rectangle(char id, int w, int h)
    {
        if (!this->setter(id, w, h))
        {
            cout << "Rectangle construct fail." << endl;
        }
    }
    // getter
    char getId()
    {
        return this->id;
        /*
            cannot use this.width,
            because:
                'this' not a object,
                'this' is a pointer.
        */
    }
    int getWidth()
    {
        return this->width;
    }
    int getHeight()
    {
        return this->height;
    }
    // setter
    bool setter(char, int, int);
    // public member function
    void consoleRecAttr();
};

// pulic method, in Rectangle
bool Rectangle::setter(char id, int w, int h)
{
    this->id = id;
    if (w > 0 && h > 0)
    {
        this->width = w;
        this->height = h;
        return true; // success.
    }
    else
    {
        cout << "Input error: width = " << w << ", height = " << h << endl;
        return false; // fail.
    }
}
int Rectangle::area()
{
    return width * height;
}
int Rectangle::perimeter()
{
    return 2 * (this->width + this->height);
}

void Rectangle::consoleRecAttr()
{
    cout << "id: " << this->id << ", width: " << this->width << ", height: " << this->height << endl;
    cout << "area: " << this->area() << ", perimeter: " << this->perimeter() << endl;
    cout << "size of Rectangle: " << sizeof(*this) << endl;
}

void consoleDivider();
// main
int main(void)
{
    Rectangle rec1('A', 20, 13);
    // rec1.setter('A', 20, 17);
    rec1.consoleRecAttr();
    consoleDivider();

    consoleDivider();
    system("pause");
    return 0;
}

// implements
void consoleDivider()
{
    cout << " - - - - - - - - - - - - - - - - - - - - " << endl;
}
