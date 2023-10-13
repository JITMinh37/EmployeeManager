#ifndef LISTMD_H
#define    LISTMD_H
#include "HashTable.cpp"

class ListMD{
    private:
        HashTable<MD> table;
    public:
        ListMD(string);
        ListMD();
        ~ListMD();
        void Add(const MD&);
        void Delete(const string&);
        MD Search(string);
        bool Exis(string);
        bool CheckID(string);
        void Update(string,int);
        void Show();
        void InputData();
        void OutData();
        friend class ListEmployee;
};

#endif  //END LISTMD_H