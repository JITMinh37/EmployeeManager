#ifndef MD_H
#define MD_H
#include <iostream>

using namespace std;

class MD{
    private:
        string MDName;
        string ID;
    public:
        MD(string = "",string = "");
        MD(const MD&);
        ~MD();
        //set Function
        void setMDName(string);
        void setMDID(string);
        //get Function
        string getMDName();
        string getID();
        // Function
        void ShowWithPosition();
        void ShowWithEmployee();
        void Show();
        void ShowWithStatistic(int,int,long long,long long);
        //Multiplication of Operators
        friend istream& operator >> (istream&, MD&);
        friend ostream& operator << (ostream&, const MD&);
};

#endif  // END MD_H