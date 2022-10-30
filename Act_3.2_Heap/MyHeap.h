// Act 3.2 - Árbol Heap: Implementando una fila priorizada
// Diego Curiel Castellanos - A01640372

#ifndef MYHEAP_H
#define MYHEAP_h

class MyHeap
{
    private:
        int* values; // Arreglo
        int size; // Cantidad de valores almacenados
        int len; // Tamaño arreglo, inicia en 7
        void setLen(int len); // Usado para expansion de arreglo
        void cambio(int a, int b); // Swith

    public:
        MyHeap(); // Iniciar len en 7
        void push(int n); // Cuando necesario, crecer arreglo 2n + 1
        void pop();
        int top(); // Regresa -1 si el arreglo esta vacio
        bool isEmpty(); // True si el arreglo esta vacio
        int length(); // Cantidad de datos almacenados
        void imprimir(); // Imprimir

};

#endif // MYHEAP_H