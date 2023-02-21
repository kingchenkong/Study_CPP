#include <iostream>
#include <cstdlib>

#include <cstring>

using namespace std;

// method declarations
void constructRectangleField();

void consoleDivider();
void manualDestroy();

char *charArrayCopy(char *);

// declarations
class Rectangle
{
    // static variable: already construct count
    static int constructCount;
    static int destoredCount;
    // private: // default is private.
    char id, *title = NULL;
    int width;
    int height;
    // private memeber function
    int area();
    int perimeter();

    void consoleConstructFail(char id)
    {
        cout << "' " << id << " ', Rectangle construct fail." << endl;
    }
    void constructorSuccess()
    {
        constructCount++;
        Rectangle::consoleConstructCount();
    }
    void afterConstruct(bool success, char id)
    {
        if (success)
        {
            constructorSuccess();
        }
        else
        {
            consoleConstructFail(id);
        }
    }

public:
    // constructor
    Rectangle(char id, char *t, int w, int h)
    {
        bool success = this->setter(id, t, w, h);
        afterConstruct(success, id);
    }

    Rectangle(char id, int w, int h)
    {

        bool success = this->setter(id, "Default Title", w, h);
        afterConstruct(success, id);
    }
    Rectangle(int w, int h)
    {
        bool success = this->setter('Z', "Default Title", w, h);
        afterConstruct(success, id);
    }

    // copy construct
    Rectangle(const Rectangle *rec)
    {
        cout << "copy constructor is called, rec: " << rec << endl;
        bool success = this->setter(rec->id, charArrayCopy(rec->title), rec->width, rec->height);
        afterConstruct(success, rec->id);
    }

    Rectangle(Rectangle &rec)
    {
        // here is => override 'default' copy constructor,
        // if no this function, will let 'recReplica2' delete fail.
        // need to know more about to Memory: 'stack' & 'heap'.
        cout << "copy constructor is called, rec: " << &rec << endl;
        bool success = this->setter(rec.id, charArrayCopy(rec.title), rec.width, rec.height);
        afterConstruct(success, rec.id);
    }

    // destructor
    ~Rectangle()
    {
        // cout << "~aaaa, 1" << endl;
        if (title != NULL)
        {
            // cout << "~aaaa, 2" << endl;
            delete title;
            // cout << "~aaaa, 3" << endl;
            title = NULL;
            // cout << "~aaaa, 4" << endl;
        }
        // else
        // {
        //     cout << "~aaaa, 5" << endl;
        // }

        cout << "===========> Rectangle <" << this->id << "> is destroy." << endl;
        destoredCount++;
        Rectangle::consoleDestroyedCount();
        // system("pause");
        // use to see the console, sause destroy will 'auto execute' at the main() end.
        // if use pointer to store the Object, that will 'not' auto destroy. need to manual destroy.
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
    char *getTitle()
    {
        return this->title;
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
    bool setter(char, char *, int, int);
    // public member function
    void consoleRecAttr();
    static void consoleConstructCount();
    static void consoleDestroyedCount();
    static void destroyRectangle(Rectangle *);
};

// pulic method, in Rectangle
bool Rectangle::setter(char id, char *text, int w, int h)
{
    cout << "setter: id: " << id << ", title: " << text << ", w: " << w << ", h: " << h << endl;
    this->id = id;
    this->title = charArrayCopy(text);

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
    cout << "  size of Rectangle: " << sizeof(*this) << endl;
    cout << "  id: " << this->id << ", width: " << this->width << ", height: " << this->height;
    cout << ", area: " << this->area() << ", perimeter: " << this->perimeter() << endl;
    cout << "  title: " << this->title << endl;
}

void Rectangle::consoleConstructCount()
{
    cout << " construct count: " << Rectangle::constructCount << endl;
}

void Rectangle::consoleDestroyedCount()
{
    cout << "destroyed count: " << Rectangle::destoredCount << endl;
}

void Rectangle::destroyRectangle(Rectangle *rec)
{
    if (rec != NULL)
    {
        cout << "==> destory: ";
        delete rec;
        // rec = new Rectangle('T', "Test delete", 8, 17);
        rec = NULL;
        // rec->consoleRecAttr();
    }
    else
    {
        cout << "Error: rec is NULL now." << endl;
    }
}

// field
Rectangle *recField1 = NULL;
Rectangle *recField2 = NULL;
Rectangle *recField3 = NULL;

// pre-set
int Rectangle::constructCount = 0;
int Rectangle::destoredCount = 0;

// main
int main(void)
{
    cout << "// pre construct Rectangle" << endl;
    Rectangle::consoleConstructCount();
    consoleDivider();

    cout << "// normal construct" << endl;
    Rectangle rec1('A', 20, 13);
    // rec1.setter('A', 20, 17);
    rec1.consoleRecAttr();
    consoleDivider();

    cout << "// construct class by 'new', and use pointer" << endl;
    Rectangle *rec2 = new Rectangle(6, 7);
    rec2->consoleRecAttr();
    Rectangle::destroyRectangle(rec2);
    consoleDivider();

    cout << "// reference the 'rec1' , use reference" << endl;
    Rectangle &refRec1 = rec1;
    refRec1.setter('a', "Reference use", 11, 4);
    refRec1.consoleRecAttr();
    consoleDivider();

    cout << "// construct field Rectangle obj" << endl;
    constructRectangleField();
    consoleDivider();

    cout << "// copy constructor test" << endl;
    Rectangle *recReplica = new Rectangle(recField3);
    delete recField3;
    recField3 = NULL;
    recReplica->consoleRecAttr();

    Rectangle *recReplica2 = new Rectangle(*recField2);
    delete recField2;
    recField2 = NULL;
    recReplica2->consoleRecAttr();
    /*  cause here use 'default' copy consturctor,
        recField2->title
            is a 'already delete' and 'set to NULL' pointer now.
        so recReplica2->title will show wrong string.
    */
    cout << "// destroyed replicas " << endl;
    char *titleReplica = recReplica->getTitle();
    char **address = &titleReplica;
    cout << "@@@@@@@@@@@@@@@@@@@@@ titleReplica: " << titleReplica << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@ address: " << address << endl;
    Rectangle::destroyRectangle(recReplica);
    cout << "@@@@@@@@@@@@@@@@@@@@@ titleReplica: " << titleReplica << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@ address: " << address << endl;

    Rectangle::destroyRectangle(recReplica2);

    consoleDivider();
    manualDestroy();
    cout << " # # # # # # # # # # # # # # # # # # # # " << endl;
    system("pause");
    return 0;
}

// implements
void constructRectangleField()
{
    recField1 = new Rectangle('b', "Field Rec 1", 2, 3);
    recField1->consoleRecAttr();
    recField2 = new Rectangle('c', "Field Rec 2", 3, 4);
    recField2->consoleRecAttr();
    recField3 = new Rectangle('d', "Field Rec 3", 4, 5);
    recField3->consoleRecAttr();
}

void consoleDivider()
{
    cout << " - - - - - - - - - - - - - - - - - - - - " << endl;
}

void manualDestroy()
{
    cout << "===== manualDestroy =====" << endl;
    Rectangle::destroyRectangle(recField1);
    Rectangle::destroyRectangle(recField2);
    Rectangle::destroyRectangle(recField3);
}

char *charArrayCopy(char *text)
{
    char *charArr = new char[strlen(text + 1)];
    /*
        here is 'new' char*, => 'heap' Memory.
        so need to 'delete', after use.
        need more knowledge to  Memeory control.
     */
    strcpy(charArr, text); // strlen(), strcpy(): #include <cstring>
    return charArr;
}