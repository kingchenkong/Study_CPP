#include <iostream>
#include <cstdlib>

using namespace std;

// declarations
enum Month
{
    January,
    February,
    March,
    April,
    May,
    June,
    July = 17,
    August,
    September,
    October,
    November,
    December
};
void consoleDivider();

int main(void)
{
    cout << "Jan: " << January << endl;
    cout << "Feb: " << February << endl;
    cout << "Mar: " << March << endl;
    cout << "Apr: " << April << endl;
    cout << "May: " << May << endl;
    cout << "Jun: " << June << endl;
    cout << "Jul: " << July << endl;
    cout << "Aug: " << August << endl;
    cout << "Sep: " << September << endl;
    cout << "Oct: " << October << endl;
    cout << "Nov: " << November << endl;
    cout << "Dec: " << December << endl;
    consoleDivider();

    cout << "size of Month: " << sizeof(Month) << endl;
    Month month1 = March;
    cout << "month1: " << month1 << endl;
    Month month2 = static_cast<Month>(3);
    cout << "month2: " << month2 << endl;
    cout << "month2 == April? " << (month2 == April ? "yes" : "no") << endl;
    Month month3 = static_cast<Month>(month2 + 2); // valid, Jun is 5.
    cout << "month3: " << month3 << endl;
    Month month4 = static_cast<Month>(month2 + 4); // invalid, 7 is nothing, that need to be careful using.
    cout << "month3: " << month4 << endl;
    consoleDivider();

    Month thisMonth = December;
    switch (thisMonth)
    {
    case January:
        cout << "is First Month." << endl;
        break;
    case 22:
        cout << "is Last Month, December is 22 now" << endl;
        break;
    default:
        cout << "thisMonth is: " << thisMonth << endl;
    }

    consoleDivider();
    system("pause");
    return 0;
}

// implements
void consoleDivider()
{
    cout << " - - - - - - - - - - - - - - - - - - - - " << endl;
}
