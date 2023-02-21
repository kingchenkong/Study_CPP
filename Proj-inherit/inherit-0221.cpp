#include <iostream>
#include <cstdlib>

using namespace std;

// declaration: class
// - super
class Windows
{
private:
    int id;
    int width, height;

public:
    // constructor
    // Windows(int i = -1, int w = 10, int h = 10) : id(i), width(w), height(h)
    // {
    //     cout << "Windows(), constructor is called..." << endl;
    // }
    Windows() : id(-1), width(10), height(10)
    {
        cout << " Windows(), is called.." << endl;
    }
    Windows(int w, int h) : id(-2), width(w), height(h)
    {
        cout << " Windows(int w, int h), is called.." << endl;
    }
    Windows(int i, int w, int h) : id(i), width(w), height(h)
    {
        cout << " Windows(int i, int w, int h), is called.." << endl;
    }

    // member function
    void showMember()
    {
        cout << "  Windows (id= " << this->id << ", width= " << this->width << ", height= " << this->height << ")" << endl;
    }

    // static function
    static void showSizeOf(Windows win);
};

void Windows::showSizeOf(Windows win)
{
    cout << "size => " << sizeof(win) << " Byte" << endl;
}

// - child
class TextWindows : public Windows
{
private:
    string text;

public:
    // constructor
    TextWindows(string t) : text(t)
    {
        cout << " TextWindows(), is called.." << endl;
    }
    TextWindows(int w, int h, string t) : Windows(w, h), text(t)
    {
        cout << " TextWindows(int w, int h), is called.." << endl;
    }
    TextWindows(int i, int w, int h, string t) : Windows(i, w, h), text(t)
    {
        this->text = t;
        cout << " TextWindows(int i, int w, int h), is called.." << endl;
    }

    // member function
    void showText()
    {
        cout << "  TextWindows (text= " << this->text << ")" << endl;
    }
};

// declaration: funciton
void consoleDivider()
{
    cout << "--------------------------------" << endl;
}

// declaration: field variables, hint: must initialize...

// main
int main()
{
    cout << "#### Windows ####" << endl;
    cout << "#### win1" << endl;
    Windows *win1 = new Windows();
    win1->showMember();
    Windows::showSizeOf(*win1);

    cout << "#### win2" << endl;
    Windows win2(11, 12);
    win2.showMember();
    Windows::showSizeOf(win2);

    cout << "#### win3" << endl;
    Windows win3(1, 20, 30);
    win3.showMember();
    Windows::showSizeOf(win3);
    consoleDivider();

    cout << "#### TextWindows ####" << endl;
    cout << "#### tWin1" << endl;
    TextWindows tWin1("tWin1, Hello World!!");
    tWin1.showMember();
    tWin1.showText();
    Windows::showSizeOf(tWin1);

    cout << "#### tWin2" << endl;
    TextWindows tWin2(13, 20, "tWin2, try try see..");
    tWin2.showMember();
    tWin2.showText();
    Windows::showSizeOf(tWin2);

    cout << "#### tWin3" << endl;
    TextWindows tWin3(5, 15, 25, "tWin3, OHOHOHOHOHOH!!!");
    tWin3.showMember();
    tWin3.showText();
    Windows::showSizeOf(tWin3);
    consoleDivider();

    cout << "#### end ####" << endl;
    consoleDivider();
    system("pause");
    return 0;
}
