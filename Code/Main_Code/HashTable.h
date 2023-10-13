#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "LinkedList.cpp"

template <class T>
class HashTable{
    private:
        int Size;
        LinkedList<T> *table;
    public:
        HashTable(int = 10);
        ~HashTable();
        int getSize();
        int hashFunction(string);
        bool addToTable(T);
        bool delFromTable(string);
        T findInTable(string);
        bool Exis(string);
        void traverseTable();
        LinkedList<T>& operator[](int );
};

#endif      // HASHTABLE_H