#include <fstream>
#include <iostream>
#include "LinkedList.h"
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList(){
    while (head  != NULL)
    {
        Node *p = head;
        head = p->next;
        delete p;
    };
    delete head;
}

template <class T>
int LinkedList<T>::listLength(){
    int length = 0;
    Node *temp = this->head;
    for(temp; temp!= NULL; temp = temp->next){
        ++length;
    }
    return length;
}

template <class T>
T LinkedList<T>::getNode(int position){
    int k =0;
    Node *temp = this->head;
    while(k != position && temp != NULL){
        temp = temp->next;
        ++k;
    }
    return temp->data;
}

template <class T>
bool LinkedList<T>::delNode(string ID){
    int position = this->findNode(ID);
    int k = 0;
    Node *temp = this->head;

    // if list is empty or Position is not in the list
    if(head == NULL || position == -1)
        return false;
    
    // if the Node want to find is the first Node
    if(this->head->next == NULL || position == 0){
        this->head = this->head->next;
    }
    //other case
    else{
        while(temp != NULL && k != position - 1){
            temp = temp->next;
            ++k;        // go the Node which is before the Node need to delete
        }
        temp->next = temp->next->next;
    }
    return true;
}

// add new Node to the head of list
template <class T>
bool LinkedList<T>::addNode(T NewP){
    // List is empty or new word is not in the list => add
    if(this->isEmpty() || this->findNode(NewP.getID())){
        Node *temp = new Node();
        temp->data = NewP;
        temp->next = this->head;
        head = temp;
        return true;
    }

    // if Position has already in list => false
    else{
        return false;
    }
}   

template <class T>
bool LinkedList<T>::isEmpty(){
    if(this->head == NULL){
        return true;
    }return false;
}

template <class T>
int LinkedList<T>::findNode(string ID){
    Node *temp = this->head;
    int position = 0;
    for(temp; temp!= NULL; temp = temp->next){
        if(temp->data.getID() == ID){
            return position;
        }
        ++position;
    }
    return -1;  // node isn't in the list so return -1
}

template <class T>
void LinkedList<T>::printList(){
    Node *temp = this->head;
    for(temp; temp != NULL;temp = temp->next){
        cout << temp->data;
    }
}

template <class T>
T& LinkedList<T>::operator[](int index){
    int k=0;
    Node *temp = this->head;
    while(k != index && temp != NULL){
        temp = temp->next;
        ++k;
    }
    return temp->data;
}

#endif  // END LINKEDLIST_CPP