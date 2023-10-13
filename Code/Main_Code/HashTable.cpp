#include "HashTable.h"
#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

template<class T>
int HashTable<T>::getSize(){
    return this->Size;
}

template <class T>
HashTable<T>::HashTable(int size){
    this->Size = size;
    table = new LinkedList<T>[this->Size];
}

template <class T>
HashTable<T>::~HashTable(){
    delete[] table;
}

template <class T>
int HashTable<T>::hashFunction(string ID){
    int i = (ID[0]-48)*10 + (ID[1]-48);
    return i%Size;
}

template <class T>
bool HashTable<T>::addToTable(T Input){
    bool check;
    int position = hashFunction(Input.getID());
    check = table[position].addNode(Input);
    return check;
}

template <class T>
bool HashTable<T>::delFromTable(string ID){
    bool check;
    int index = hashFunction(ID);
    check = table[index].delNode(ID);
    return check;
}

template <class T>
void HashTable<T>::traverseTable(){
    for(int i=0 ; i < Size ; i++){
        table[i].printList();
    }
}

template <class T>
LinkedList<T>& HashTable<T>::operator[](int index){
    return this->table[index];
}

template<class T>
T HashTable<T>::findInTable(string ID){
    static T temp;
    int VT = hashFunction(ID);
    int position = table[VT].findNode(ID);

    // check if the list is empty or this Position isn't in the list
    if(this->table[VT].isEmpty() || position == -1){
        return temp;
    }
    else{
        return table[VT][position];
    }
}

template<class T>
bool HashTable<T>::Exis(string ID){
    int VT = hashFunction(ID);
    int position = table[VT].findNode(ID);

    if(this->table[VT].isEmpty() || position == -1){
        return false;
    }else{
        return true;
    }
}

#endif    // END HASHTABLE_CPP