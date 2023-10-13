#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.cpp"

class Employee : public Person{
    private:
        int Day;
        long long Money;
        int Allowance;
        long long Fine;
    public:
        Employee();
        Employee(string,string,string,string,string,bool,Date,int,long long,int,long long);
        Employee(const Person&,int = 0,int = 0,long long = 0,long long = 0);
        ~Employee();
        //setFunction;
        void setDay(int);
        void setMoney(long long);
        void setAllowance(int);
        void setFine(long long);
        //getFunction
        int getDay();
        long long getMoney();
        int getAllowance();
        long long getFine();
        //CalSalaryFunction
        long long Salary();
        //ShowFunction
        void ShowBySearch();
        void Show(int);
        //Multiplication of operators
        friend istream& operator>>(istream& ,Employee&);
        friend ostream& operator<<(ostream& ,Employee&);
        friend class ListEmployee;
};

#endif      // END EMPLOYEE_H