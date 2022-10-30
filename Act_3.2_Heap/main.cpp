// Act 3.2 - Árbol Heap: Implementando una fila priorizada
// Diego Curiel Castellanos - A01640372

#include <iostream>
#include "MyHeap.h"

using namespace std;

int main()
{
    MyHeap ea;

    cout << "Vacia?: " << endl;
    cout << ea.isEmpty() << endl << endl;

    cout << "Siguiente elemento: " << endl;
    cout << ea.top() << endl << endl;

    ea.push(28);
    ea.push(21);
    ea.push(17);
    ea.push(19);
    ea.push(5);
    ea.push(8);

    cout << "Vacia?: " << endl;
    cout << ea.isEmpty() << endl << endl;

    ea.imprimir();
    cout << endl << endl;

    cout << "Siguiente elemento: " << endl;
    cout << ea.top() << endl << endl;

    cout << "POP" << endl;
    ea.pop();
    cout << endl;

    cout << "Siguiente elemento: " << endl;
    cout << ea.top() << endl << endl;

    ea.imprimir();
    cout << endl << endl;

    cout << "Cantidad de datos almacenados: " << endl;
    cout << ea.length() << endl << endl;

    return 0;
}
