#ifndef MY_HASH_TABLE_H
#define MY_HASH_TABLE_H

#include <vector>
#include <list>
#include <string>
#include <set>
#include "Ip.h"
#include "Fecha.h"

class MyHashTable
{
    public:
        MyHashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(Ip key, Fecha);
        std::multiset<Fecha> get(Ip key);
        void remove(Ip key);
    private:
        std::vector<std::list<std::pair<Ip, std::multiset<Fecha>>>> *table;
        int size; // Cantidad de datos que tenemos en la tabla
        int length; // Tamaño de la tabla
        int getPos(Ip key);
        void rehashing();
};

#endif // MY_HASH_TABLE_H
