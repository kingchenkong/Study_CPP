#include <iostream>
#include <cstdlib>

using namespace std;

// declarations
class Rectangle
{
private:
    char id;
    int width;
    int height;

public:
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
    void setId(char id)
    {
        this->id = id;
    }
    void setWidth(int width)
    {
        this->width = width;
    }
    void setHeight(int height)
    {
        this->height = height;
    }
    // member function
    int area();
    int perimeter();
    void consoleRecAttr();
};

// pulic method, in Rectangle
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
    Rectangle rec1;
    rec1.setId('A');
    rec1.setWidth(20);
    rec1.setHeight(13);
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
