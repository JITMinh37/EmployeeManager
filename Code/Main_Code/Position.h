#include <iostream>
#include <string.h>
#ifndef POSITION_H
#define POSITION_H

using namespace std;

class Position{
    private:
        int Allowance;
        long long Money;
        string PositionName;
        string PositionID;
    public:
        // Construction & Destruction Function
        Position(int =0,long long =0,string ="",string ="");
        ~Position();
        //setFunction
        void setAllowance(int);
        void setMoney(long long);
        void setPoName(string);
        void setPoID(string);
        //getFunction
        int getAllowance();
        long long getMoney();
        string getPoName();
        string getID();
        string getIDMD();
        //Function
        void Show();
        void ShowWithEmployee();
        void ShowWithStatistic(int,int,long long,long long) const;
        //Multiplication of operators
        friend istream& operator>>(istream&,Position&);
        friend ostream& operator<<(ostream&,const Position&);
};

#endif  //END POSITION_H