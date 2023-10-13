#ifndef PERSON_H
#define PERSON_H

#include "Date.cpp"
#include <string>

class Person{
    protected:
        string ID;
        string Name;
        string Tel;
        string CCCD;
        string Add;
        bool Sex;
        Date birthDate;
        string NPoistion;
        string NMD;
    public:
        Person(string="",string="",string="",string="",string="",bool=0,Date= Date());
        ~Person();
        //set Function
        void setID(string);
        void setTel(string);
        void setCCCD(string);
        void setAdd(string);
        void setSex(bool);
        void setBirthDate(Date);
        void setName(string);
        void setNPosition(string);
        void setNMD(string);
        //get Function
        string getIDPosition();
        string getIDPerson();
        string getTel();
        string getCCCD();
        string getAdd();
        bool getSex();
        Date getBirthDate();
        string getName();
        string getNPosition();
        string getNMD();
        string getIDMD();
        // Check input Function
        bool checkCCCD(const string&);
        bool checkTel(const string&);
        // Show Function
        void Show(int i);
        //Multiplication of operators
        friend istream &operator>>(istream &, Person &);
        friend ostream &operator<<(ostream &, const Person &);
}; 

#endif  // END PERSON_H