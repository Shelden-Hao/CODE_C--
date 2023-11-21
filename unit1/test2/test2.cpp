#include <iostream>
using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};
class Employee : public Date
{
public:
    string name;
    Employee(string name, int year, int month, int day)
    {
        this->name = name;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    bool isBirthday(Date d)
    {
        if (d.year == year && d.month == month && d.day == day)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Employee Tom("Tom", 1, 2, 1);
    Date date(1, 2, 1);
    if (Tom.isBirthday(date))
    {
        cout << "Tom's birthday is today" << endl;
    }
    return 0;
}