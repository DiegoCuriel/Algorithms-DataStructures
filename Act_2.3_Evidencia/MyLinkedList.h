#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include <iostream>
#include "Registro.h"

struct Node
{
    Registro data;
    Node *next;
    Node(Registro data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class MyLinkedList
{
    public:      
        MyLinkedList();
        ~MyLinkedList();
        int length();
        bool isEmpty();
        Registro first();
        Registro last();
        Registro getAt(int pos);
        void setAt(Registro data, int pos);
        void insertFirst(Registro data);
        void insertLast(Registro data);
        void insertAt(Registro data, int pos); //pos:[0,size] Exc invalid_argument
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        friend std::ostream &operator<<(std::ostream &, const MyLinkedList &);
        void consulta(std::ostream &, Registro l, Registro r);
        void mergeSort();
    private:
        Node *head;
        Node *tail;
        int size;
        Node* mitad(Node *head);
        Node* merge(Node *h1, Node *h2);
        Node* mergeSort(Node *head);
};

#endif // MY_LINKED_LIST_H