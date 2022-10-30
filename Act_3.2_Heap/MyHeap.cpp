// Act 3.2 - Árbol Heap: Implementando una fila priorizada
// Diego Curiel Castellanos - A01640372

#include <iostream>
#include "MyHeap.h"

using namespace std;

MyHeap::MyHeap() // O(1)
{
    this->len = 7;
    this->values = new int[this->len];
    this->size = 0;
}

void MyHeap::push(int n) // O(Log n), Expandir el arreglo tiene una complejidad adicional de O(n)
{
    if (isEmpty()) // Arreglo vacio
    {
        values[0] = n;
        this->size++;
        return;
    }
    if (len == size) // Expandir arreglo
    {
        int ntam = (2 * this->len) + 1;
        int* tmp = new int[ntam];
        for (int i = 0; i < len; i++)
        {
            tmp[i] = this->values[i];
        }
        this->values = tmp;
        setLen(ntam);
    }
    this->values[size] = n; //Insertar valor al final
    this->size++;
    
    int w = this->size - 1;
    while (w > 0) // Re ajustar el arreglo
    {
        int p = (w - 1) / 2;
        if (this->values[p] < this->values[w]) // Si el padre actual es menor cambio
        {
            cambio(p, w);
            w = p;
        }
        else
        {
            return;
        }
    }
}

void MyHeap::pop() // O(Log n)
{
    if (isEmpty()) // Arreglo vacio
    {
        return;
    }

    this->values[0] = this->values[this->size - 1]; // Remplazar la raiz con el ultimo valor
    this->size--;

    int w = 0;
    while (w < this->size) // Re ajustar el arreglo
    {
        int left = (2 * w) + 1;
        int right = (2 * w) + 2;
        int comp = w;

        if (left < this->size && this->values[left] > this->values[comp])
        {
            comp = left;
        }
        if (right < this->size && this->values[right] > this->values[comp])
        {
            comp = right;
        }
        if (comp != w) // Si el padre no es el mayor cambio
        {
            cambio(comp, w);
            w = comp;
        }
        else
        {
            return;
        }
    }
}

int MyHeap::top() // O(1)
{
    if (isEmpty())
    {
        return -1;
    }
    return values[0];
}

bool MyHeap::isEmpty() // O(1)
{
    return this->size == 0;
}

int MyHeap::length() // O(1)
{
    return this->size;
}

void MyHeap::setLen(int len) // O(1)
{
    this->len = len;
}

void MyHeap::imprimir() // O(n)
{
    for (int i = 0; i < this->size; i++)
    {
        cout << this->values[i] << ", ";
    }
}

void MyHeap::cambio(int a, int b) // O(1)
{
    int tmp = this->values[a];
    this->values[a] = this->values[b];
    this->values[b] = tmp;
}