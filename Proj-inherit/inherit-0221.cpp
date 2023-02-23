#include <iostream>
#include <cstdlib>

using namespace std;

// declaration: class
// - super
class Windows
{
private:
    int id;
    string name;

protected:
    int width, height;

public:
    // constructor
    Windows() : id(-1), name("empty"), width(10), height(10) { cout << " Windows(), is called.." << endl; }
    Windows(int w, int h) : id(-2), name("empty"), width(w), height(h) { cout << " Windows(int w, int h), is called.." << endl; }
    Windows(int i, string n, int w, int h) : id(i), name(n), width(w), height(h) { cout << " Windows(int i, int w, int h), is called.." << endl; }
    // copy constructor
    Windows(Windows &win)
    {
        id = win.getId();
        name = win.getName();
        width = win.width;
        height = win.height;
        cout << "Windows(&win), is called.." << endl;
    }
    // destructor
    ~Windows()
    {
        cout << "id= " << id << ", name= " << name << ", ~Windows(), is called.." << endl;
    }
    // getter
    int getId() { return id; }
    string getName() { return name; }
    int getWidth() { return width; }
    int getHeight() { return height; }
    // setter
    void setName(string n) { name = n; }
    // member function
    void showMember() { cout << "  Windows (id= " << id << ", width= " << width << ", height= " << height << ")" << endl; }
    // static function
    static void showSizeOf(Windows win);
    static void showSizeOf(Windows *win);
    static void destroy(Windows *win);
};
void Windows::showSizeOf(Windows win) { cout << "size => " << sizeof(win) << " Byte" << endl; }
void Windows::showSizeOf(Windows *win) { cout << "size => " << sizeof(&win) << " Byte" << endl; }
void Windows::destroy(Windows *win)
{
    if (win != NULL)
    {
        delete win;
        win = NULL;
    }
}

// - child
class TextWindows : public Windows
{
private:
    string text;

public:
    // constructor
    TextWindows(string t) : text(t) { cout << " TextWindows(string t), is called.." << endl; }
    TextWindows(int w, int h, string t) : Windows(w, h), text(t) { cout << " TextWindows(int w, int h, string t), is called.." << endl; }
    TextWindows(int i, string n, int w, int h, string t) : Windows(i, n, w, h), text(t) { cout << " TextWindows(int i, string n, int w, int h, string t), is called.." << endl; }
    // copy constructor
    TextWindows(TextWindows &source) : Windows(source)
    {
        text = source.getText();
        cout << "TextWindows(&source), is called.." << endl;
    }
    // destructor
    ~TextWindows()
    {
        cout << "id= " << getId() << ", name= " << getName() << ", ~TextWindows(), is called.." << endl;
        /*
        here will call first, then call super class destructor.
            id= 5, name= tWin3Replica, ~TextWindows(), is called..
            id= 5, name= tWin3Replica, ~Windows(), is called..
         */
    }
    // getter
    string getText() { return text; }
    // setter
    void setText(string t) { text = t; }
    // override function
    void showMember() { cout << " TextWindows (id= " << getId() << ", width= " << width << ", height= " << height << ", text= " << text << ")" << endl; }
    // member function
    void showText() { cout << "text => " << text << ")" << endl; }
    // static function
    static void destroy(TextWindows *tWin);
};
void TextWindows::destroy(TextWindows *tWin)
{
    if (tWin != NULL)
    {
        delete tWin;
        tWin = NULL;
    }
}

// declaration: funciton
void consoleDivider()
{
    cout << "--------------------------------" << endl;
}

// declaration: field variables, hint: must initialize...
Windows *win1 = NULL;
TextWindows *tWin2 = NULL;
TextWindows *tWin3 = NULL;
TextWindows *tWin2Replica = NULL;
TextWindows *tWin3Replica = NULL;

void destroy()
{
    Windows::destroy(win1);
    Windows::destroy(tWin2);
    Windows::destroy(tWin3);
    Windows::destroy(tWin2Replica);
    TextWindows::destroy(tWin3Replica);
}

// main
int main()
{
    cout << "#### Windows ####" << endl;
    cout << "#### win1" << endl;
    win1 = new Windows();
    win1->setName("win1");
    win1->showMember();
    Windows::showSizeOf(*win1);

    cout << "#### win2" << endl;
    Windows win2(11, 12);
    win2.setName("win2");
    win2.showMember();
    Windows::showSizeOf(win2);

    cout << "#### win3" << endl;
    Windows win3(1, "win3", 20, 30);
    win3.showMember();
    Windows::showSizeOf(win3);
    consoleDivider();

    cout << "#### TextWindows ####" << endl;
    cout << "#### tWin1(\"Hello World!!\")" << endl;
    TextWindows tWin1("Hello World!!");
    tWin1.setName("tWin1");
    tWin1.showMember();
    tWin1.showText();
    Windows::showSizeOf(tWin1);

    cout << "#### tWin2(13, 20, \"try try see..\")" << endl;
    tWin2 = new TextWindows(13, 20, "try try see..");
    tWin2->setName("tWin2");
    tWin2->showMember();
    tWin2->showText();
    Windows::showSizeOf(*tWin2);

    cout << "#### tWin3(5, 15, 25, \"OHOHOHOHOHOH!!!\")" << endl;
    tWin3 = new TextWindows(5, "tWin3", 15, 25, "OHOHOHOHOHOH!!!");
    tWin3->showMember();
    tWin3->showText();
    Windows::showSizeOf(*tWin3);
    consoleDivider();

    cout << "#### win1 copy" << endl;
    Windows win1Replica(*win1);
    win1Replica.setName("win1Replica");
    win1Replica.showMember();

    cout << "#### win3 copy" << endl;
    Windows win3Replica(win3);
    win3Replica.showMember();
    win3Replica.setName("win3Replica");
    consoleDivider();

    cout << "#### tWin2 copy" << endl;
    tWin2Replica = new TextWindows(*tWin2);
    tWin2Replica->setName("tWin1Replica");
    tWin2Replica->showMember();

    cout << "#### tWin3 copy" << endl;
    tWin3Replica = new TextWindows(*tWin3);
    tWin3Replica->setName("tWin3Replica");
    tWin3Replica->showMember();

    consoleDivider();

    cout << "#### end - destroy####" << endl;
    destroy();
    consoleDivider();

    system("pause");
    return 0;
}
