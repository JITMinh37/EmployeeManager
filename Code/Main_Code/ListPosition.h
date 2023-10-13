#ifndef LISTPOISION_H
#define    LISTPOSITION_H
#include "HashTable.cpp"
#include "ListMD.cpp"

class ListPosition{
    private:
        HashTable<Position> table;
    public:
        ListPosition(string);
        ListPosition();
        ~ListPosition();
        void Add(const Position&);
        void Delete(const string&);
        void DeleteByMD(string);
        int CountByMD(string);
        Position Search(string);
        ListPosition SearchByMD(const string&);
        bool Exis(string);
        bool CheckID(string);
        int Update(string,int);
        void ShowWithMD();
        void Show();
        void InputData();
        void OutData();
        friend class ListEmployee;
};

#endif  //END LISTPOSITION_H