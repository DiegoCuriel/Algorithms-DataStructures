#ifndef MYHASHTABLE_H 
#define MYHASHTABLE_H

#include <list>
#include <vector>

using namespace std;


class MyHashTable{
    private:
        list<tuple<string, int>> *tabla;
        int size; //num de valores que tenemos en el hash
        int sizeA; //El tamano del arreglo
        int getPos(string key);
        void rehashing();

    public:
        MyHashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(string key, int value);
        int get(string key);
        void remove(string key);


};




#endif