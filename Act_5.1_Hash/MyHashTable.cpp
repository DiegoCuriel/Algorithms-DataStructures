// Act 5.1 - Implementación individual de operaciones sobre conjuntos
// Diego Curiel Castellanos - A01640372

#include "MyHashTable.h"

#include <iostream>
#include <functional>

using namespace std;

MyHashTable::MyHashTable() // O(1)
{
    this->size = 0;
    this->sizeA = 11;
    this->table.resize(this->sizeA);
}

MyHashTable::~MyHashTable()
{}

bool MyHashTable::isEmpty() // O(1)
{
    return size == 0;
} 

int MyHashTable::getPos(string key) // O(1)
{
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    if (hashCode < 0)
    {
        hashCode = hashCode * -1;
    }
    return hashCode % this->sizeA;
}

void MyHashTable::put(string key, int value) // O(1) - sin el hashing, O(n) - con el hashing
{
    if (this->size > this->sizeA * 0.75)
    {
        rehashing();
    }
    int pos = getPos(key);
    for (auto k = this->table[pos].begin(); k != this->table[pos].end(); k++)
    {
        if (k->first == key)
        {
            k->second = value;
            return;
        }
    }
    this->table[pos].push_back(make_pair(key, value));
    this->size++;
}

void MyHashTable::rehashing() // O(n)
{
    vector<list<pair<string, int>>> tablaP = this->table;
    this->sizeA = this->sizeA * 2 + 1;
    this->table.resize(this->sizeA);
    this->size = 0;
    for (int i = 0; i < tablaP.size(); i++)
    {
        for (auto k = tablaP[i].begin(); k != tablaP[i].end(); k++)
        {
            this->put(k->first, k->second);
        }
    }
}

int MyHashTable::get(string key) // O(1)
{
    int pos = getPos(key);
    for (auto k = this->table[pos].begin(); k != this->table[pos].end(); k++)
    {
        if (k->first == key)
        {
            return k->second;
        }
    }
    return -1;
}

void MyHashTable::remove(string key) // O(1)
{
    int pos = getPos(key);
    for (auto k = this->table[pos].begin(); k != this->table[pos].end(); k++)
    {
        if (k->first == key)
        {
            this->table[pos].erase(k);
            this->size--;
            return;
        }
    }
}