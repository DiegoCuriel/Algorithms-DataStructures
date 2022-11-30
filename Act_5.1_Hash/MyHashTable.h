// Act 5.1 - Implementación individual de operaciones sobre conjuntos
// Diego Curiel Castellanos - A01640372

#ifndef MYHASHTABLE_H 
#define MYHASHTABLE_H

#include <list>
#include <vector>
#include <string>

using namespace std;

class MyHashTable
{
    private:
        vector<list<pair<string, int>>> table;
        int size; // Cantidad de valores
        int sizeA; // Tamaño del arreglo
        int getPos(string key);
        void rehashing();

    public:
        MyHashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(string key, int value);
        int get(string key); // Regresa -1 si no se encuentra
        void remove(string key);
};

#endif // MYHASHTABLE_H