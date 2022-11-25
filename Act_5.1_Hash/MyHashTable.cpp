#include "MyHashTable.h" 

#include <iostream>
#include <list>
#include <string>
#include <functional>

MyHashTable::MyHashTable()
{
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new list<tuple<string, int>>;
}

MyHashTable::~MyHashTable()
{}

bool MyHashTable::isEmpty()
{
    return size == 0;
}

int MyHashTable::getPos(string key)
{
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    if (hashCode < 0)
    {
        hashCode = hashCode * -1;
    }
    return hashCode%this->sizeA;
}