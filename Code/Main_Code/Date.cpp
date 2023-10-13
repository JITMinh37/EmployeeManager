#include "Date.h"
#ifndef DATE_CPP
#define DATE_CPP

void TextColor(int x)
{
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

bool laNamNhuan(int nYear)
{
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
    {
        return true;
    }
    return false;
}

int tinhSoNgayTrongThang(int nMonth, int nYear)
{
    int nNumOfDays;

    switch (nMonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        nNumOfDays = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        nNumOfDays = 30;
        break;
    case 2:
        if (laNamNhuan(nYear))
        {
            nNumOfDays = 29;
        }
        else
        {
            nNumOfDays = 28;
        }
        break;
    }
    return nNumOfDays;
}

bool laNgayHopLe(int nDay, int nMonth, int nYear)
{

    if (nYear < 0)
    {
        return false;
    }

    if (nMonth < 1 || nMonth > 12)
    {
        return false;
    }
    if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
    {
        return false;
    }

    return true;
}

void takePresentTime(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    PresentDate = ltm->tm_mday;
    PresentMonth = 1 + ltm->tm_mon;
    PresentYear = 1900 + ltm->tm_year;
}

bool CheckInputData(int day, int month, int year){
    if(year > PresentYear) return false;
    else if(year == PresentYear){
        if(month > PresentMonth) return false;
        else if(month == PresentMonth){
            if(day > PresentDate) return false;
        }
    }
    return true;
}

istream &operator>>(istream &i, Date &a)
{
    cout << "(DD/MM/YYYY): " ;
    i >> a.Day >> a.Month >> a.Year;
    while (laNgayHopLe(a.Day, a.Month, a.Year) == false || CheckInputData(a.Day,a.Month,a.Year) == false)
    {   
        TextColor(4);
        cout << "\t\t\t-----------THONG BAO-----------" << endl;
        cout << "\t\t\t         Nhap sai ngay !!!"      << endl;
        cout << "\t\t\t-------------------------------" << endl;
        TextColor(7);
        cout << "\t\tNhap lai (DD/MM/YYYY): " ;
        i >> a.Day >> a.Month >> a.Year;
    }
    return i;
}

ostream& operator<<(ostream& o, const Date& a){
    o << a.Day <<"/"<< a.Month<<"/"<<a.Year;
}

int Date::getDay()
{
    return this->Day;
}

int Date::getMonth()
{
    return this->Month;
}

int Date::getYear()
{
    return this->Year;
}

void Date::setNull(){
    this->Day = 0;
    this->Month = 0;
    this->Year = 0;
}

void Date::setDay(int Day)
{
    this->Day = Day;
}

void Date::setMonth(int Month)
{
    this->Month = Month;
}

void Date::setYear(int Year)
{
    this->Year = Year;
}

Date::Date(unsigned int Day, unsigned int Month, unsigned int Year)
{
    this->Day = Day;
    this->Year = Year;
    this->Month = Month;
}

void Date::Show()
{
    std::cout << this->Day << "/" << this->Month << "/" << this->Year;
}

Date::~Date() {}

#endif  // END DATE_CPP