// Act 2.1 - Implementación de un ADT de estructura de datos lineales
// Diego Curiel Castellanos - A01640372

#ifndef MYLINKEDLIST_H 
#define MYLINKEDLIST_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    //constructor
    Node(int data, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class MyLinkedList
{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        MyLinkedList();
        ~MyLinkedList(); //destructor
        int length();
        bool isEmpty();
        int first();
        int last();
        int getAt(int pos);
        void setAt(int data,int pos);
        void insertFirst(int data);
        void insertLast(int data);
        void insertAt(int data, int pos); //pos:[0,size] Exc invalid_argument
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        friend ostream& operator<<(ostream& os,const MyLinkedList& ll);
};

#endif //MyLinkedList