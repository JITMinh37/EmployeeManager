#include "Employee.cpp"
#include "ListPosition.cpp"
#include "HashTable.cpp"
#ifndef LISTEMPLOYEE_H
#define LISTEMPLOYEE_H
#include <fstream>
#include <math.h>
#include <iostream>
#include <string>
#pragma once

using namespace std;

class ListEmployee{
    private:
        Employee *p;
        int length;
    public:
        ListEmployee();
        ListEmployee(Employee *,int);
        ~ListEmployee();
        // Process with file
        void InputDate();
        void OutDate();
        void InputFilePerson();
        void OutFilePerson();
        /*---------Function------*/
        // Insert
        void InsertAt(const Employee&,int);
        void InsertAtLast(const Employee&);
        void Insert(const string&);
        // Delete Function
        void DeleteByPosition(const string&);
        void DeleteByMD(const string&);
        void Delete(const string&);
        void DeleteAt(int);
        // Support Function
        int CountByMD(const string&);
        int CountByPosition(const string&);
        bool Exis(string ID);
        bool CheckID(string ID);
        // Update Function
        void Update(const string&);
        // Search Function
        ListEmployee SearchByPosition (const string&);
        ListEmployee SearchByMD (const string &);
        int Search(const string&);
        // Sort Function
        void Sort(char);
        void SortByMoney(char);
        // Show Function    
        void ShowWithPMD();
        void ShowPerson();
        void ShowPosition();
        // Statistic Function
        void StatisticByPosition(ListPosition = ListPosition());
        void StatisticByMD(ListMD = ListMD());
        void StatisticSum(ListPosition = ListPosition(),ListMD = ListMD());
        // Reset working days
        void ResetDay(int);
        /*-------Set&Get Function-----*/
        void setLength(int);
        int getLength();
        // Get employee's information from List Position
        void getMoney(ListPosition = ListPosition());
        void getMD(ListMD = ListMD());
        void getDay();
        // Support to Statictis
        void CountByPosition(const string&,int&,int&);
        void MoneyByPosition(const string&,long long&,long long &);
        void CountByMD(const string&,int&,int&);
        void MoneyByMD(const string&,long long&,long long &);
        /*------Multiplication of operator----*/
        friend istream& operator>>(istream&, ListEmployee&);
        friend ostream& operator<<(ostream&, ListEmployee&);
        Employee& operator[](const int& );
};

#endif  // END LISTEMPLOYEE_H