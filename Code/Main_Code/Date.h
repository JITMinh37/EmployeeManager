#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int PresentDate ;
int PresentMonth ;
int PresentYear ;


class Date
{
private:
    int Day;
    int Month;
    int Year;

public:
    Date(unsigned int = 0, unsigned int = 0, unsigned int = 0);
    ~Date();
    //void takePresentTime();
    int getDay();
    int getMonth();
    int getYear();
    void setNull();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void Show();
    friend istream &operator>>(istream &, Date &);
    friend ostream &operator<<(ostream &, const Date &);
};

#endif      // END DATE_H