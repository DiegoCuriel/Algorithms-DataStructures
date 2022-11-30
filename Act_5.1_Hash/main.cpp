// Act 5.1 - Implementación individual de operaciones sobre conjuntos
// Diego Curiel Castellanos - A01640372

#include "MyHashTable.h"
#include <iostream>

using namespace std;

int main()
{
    MyHashTable hash;

    cout << hash.isEmpty() << endl;
    hash.put("main", 88);
    cout << hash.get("main") << endl;
    cout << hash.isEmpty() << endl;
    hash.remove("main");
    cout << hash.get("main") << endl;
    cout << hash.isEmpty() << endl;

    cout << endl;

    hash.put("a", 75);
    hash.put("b", 60);
    hash.put("c", 110);
    hash.put("d", 7);
    hash.put("e", 32);
    hash.put("f", 21);
    hash.put("g", 99);
    hash.put("h", 500);
    hash.put("i", 570);
    hash.put("j", 432);
    hash.put("k", 1);
    hash.put("l", 44);
    hash.put("m", 83);

    cout << hash.get("h") << endl;
    cout << hash.get("r") << endl;
    cout << hash.get("m") << endl;
}