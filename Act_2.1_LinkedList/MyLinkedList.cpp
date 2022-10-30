// Act 2.1 - Implementación de un ADT de estructura de datos lineales
// Diego Curiel Castellanos - A01640372

#include "MyLinkedList.h" 

MyLinkedList::MyLinkedList() // O(1)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

MyLinkedList::~MyLinkedList() // O(1)
{
    Node* tmp = head;
    while (tmp != nullptr)
    {
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
}

int MyLinkedList::length() // O(1)
{
    return this->size;
}

bool MyLinkedList::isEmpty() // O(1)
{
    return this->size == 0;
}

int MyLinkedList::first() // O(1)
{
    return this->head->data;
}

int MyLinkedList::last() // O(1)
{
    return this->tail->data;
}

int MyLinkedList::getAt(int pos) // O(n)
{
    if (pos < 0 || pos >= this->size)
    {
        throw invalid_argument("Posición invalida");
    }
    Node* tmp = this->head;
    for (int i = 0; i < pos; i++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

void MyLinkedList::setAt(int data,int pos) // O(n)
{
    if (pos < 0 || pos >= this->size)
    {
        throw invalid_argument("Posición invalida");
    }
    Node* tmp = this->head;
    for (int i = 0; i < pos; i++)
    {
        tmp = tmp->next;
    }
    tmp->data = data;
}

void MyLinkedList::insertFirst(int data) // O(1)
{
    if (isEmpty())
    {
        this->head = this->tail = new Node(data);
    }
    else
    {
        this->head = new Node(data, this->head);
    }
    this->size++;
}

void MyLinkedList::insertLast(int data) // O(n)
{
    if (isEmpty())
    {
        this->head = this->tail = new Node(data);
    }
    else
    {
        this->tail->next = new Node(data);
        this->tail = this->tail->next;
    }
    this->size++;
}

void MyLinkedList::insertAt(int data, int pos) // O(n)
{
    if (pos < 0 || pos > this->size)
    {
        throw invalid_argument("Posición invalida");
    }
    else if (pos == 0)
    {
        insertFirst(data);
    }
    else if (pos == size)
    {
        insertLast(data);
    }
    else
    {
        Node* tmp1 = new Node(data);
        Node* tmp2 = head;
        for (int i = 0; i < pos - 1; i++)
        {
            tmp2 = tmp2->next;
        }
        tmp1->next = tmp2->next;
        tmp2->next = tmp1;
        size++;
    }
}

void MyLinkedList::removeFirst() // O(1)
{
    if (isEmpty())
    {
        throw invalid_argument("Lista vacia");
    }
    else
    {
        Node* tmp = this->head;
        this->head = this->head->next;
        delete tmp;
        size--;
    }
}

void MyLinkedList::removeLast() // O(n)
{
    if (isEmpty())
    {
        throw invalid_argument("Lista vacia");
    }
    else
    {
        Node* tmp = this->head;
        Node* tmp2 = this->head;
        while (tmp->next != nullptr)
        {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        tmp2->next = nullptr;
        delete tmp;
        size--;
    }
}

void MyLinkedList::removeAt(int pos) // O(n)
{
    if (isEmpty())
    {
        throw invalid_argument("Lista vacia");
    }
    else if (pos < 0 || pos >= this->size)
    {
        throw invalid_argument("Posición invalida");
    }
    else if (pos == 0)
    {
        removeFirst();
    }
    else if (pos == size - 1)
    {
        removeLast();
    }
    else
    {
        Node* tmp = this->head;
        Node* tmp2 = this->head;
        while (pos != 0)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            pos--;
        }
        tmp2->next = tmp->next;
        delete tmp;
        size--;
    }
}

ostream& operator<<(ostream& os,const MyLinkedList& ll) // O(1)
{
    Node* tmp = ll.head;
    while (tmp != nullptr)
    {
        os << tmp->data << ",";
        tmp = tmp->next;
    }
    return os;
}