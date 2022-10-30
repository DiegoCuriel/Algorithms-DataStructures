#include <iostream>
#include "MyLinkedList.h"

using namespace std;

int main()
{
    MyLinkedList lista;
    cout << lista.isEmpty() << endl;
    lista.insertFirst(3);
    lista.insertFirst(5);
    lista.insertLast(8);
    cout << lista << endl;
    lista.insertAt(60,2);
    cout << lista << endl;
    lista.insertAt(61,0);
    lista.insertAt(62,5);
    cout << lista << endl;
    cout << lista.first() << endl;
    cout << lista.last() << endl;
    cout << lista.length() << endl;
    cout << lista.isEmpty() << endl;
    
    return 0;
}