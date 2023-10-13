#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "MD.cpp"
#include "Position.cpp"
#include "Employee.cpp"
#include <iostream>
using namespace std;

template <class T>
class LinkedList{
    private:
        class Node{
            public:
                T data;
                Node *next;
            public:
                Node(){
                    next = NULL;
                }
        };
        Node *head;
    public:
        LinkedList();
        ~LinkedList();
        int listLength();
        T getNode(int);
        bool delNode(string);
        bool addNode(T);
        bool isEmpty();
        int findNode(string);
        void printList();
        T& operator[](int);
};

#endif  // END LINKEDLIST_H