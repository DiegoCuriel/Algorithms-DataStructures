#include "MyHashTable.h"

#include <functional>

MyHashTable::MyHashTable() : size(0), length(11)
{
    // Complejidad: O(1)

    this->table = new std::vector<std::list<std::pair<Ip, std::multiset<Fecha>>>>(this->length);
}

MyHashTable::~MyHashTable()
{
    // Complejidad: O(length + size + |fechas|)

    delete this->table;
}

bool MyHashTable::isEmpty()
{
    // Complejidad: O(1)

    return this->size == 0;
}

void MyHashTable::put(Ip key, Fecha value)
{
    /*
    Complejidad asumiendo que no ocurre rehashing y que la tabla está
    dispersa: O(|key| + log(|fechas|))
    */

    if (4 * (this->size + 1) > 3 * this->length)
    {
        this->rehashing();
    }
    int pos = this->getPos(key);
    for (auto i = this->table->at(pos).begin(); i != this->table->at(pos).end(); ++i)
    {
        if (i->first == key)
        {
            i->second.insert(value);
            return;
        }
    }
    this->table->at(pos).push_back({key, {value}});
    ++this->size;
}

std::multiset<Fecha> MyHashTable::get(Ip key)
{
    // Complejidad asumiendo que la tabla está dispersa: O(|key| + log(|fechas|))

    int pos = this->getPos(key);
    for (auto i = this->table->at(pos).begin(); i != this->table->at(pos).end(); ++i)
    {
        if (i->first == key)
        {
            return i->second;
        }
    }
    this->put(key, {});
    return {};
}

void MyHashTable::remove(Ip key)
{
    // Complejidad asumiendo que la tabla está dispersa: O(|key| + log(|fechas|))

    int pos = this->getPos(key);
    for (auto i = this->table->at(pos).begin(); i != this->table->at(pos).end(); ++i)
    {
        if (i->first == key)
        {
            this->table->at(pos).erase(i);
            --this->size;
            return;
        }
    }
}

int MyHashTable::getPos(Ip key)
{
    // Complejidad: O(|key|)

    size_t hashC = std::hash<std::string>{}(key.getIp());
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->length;
}

void  MyHashTable::rehashing()
{
    // Complejidad: O(length + size + sum(|key|) + |fechas|)

    this->length = 2 * this->length + 1;
    std::vector<std::list<std::pair<Ip, std::multiset<Fecha>>>> *temp = 
            new std::vector<std::list<std::pair<Ip, std::multiset<Fecha>>>>(this->length);
    for (int i = 0; i < this->table->size(); ++i)
    {
        for (auto j = this->table->at(i).begin(); j != this->table->at(i).end(); ++j)
        {
            int pos = this->getPos(j->first);
            temp->at(pos).push_back(*j);
        }
    }
    delete this->table;
    this->table = temp;
}
