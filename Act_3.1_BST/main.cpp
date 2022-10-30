// Act 3.1 - Operaciones avanzadas en un BST
// Diego Curiel Castellanos - A01640372

#include <iostream>
#include "MyBST.h"
#include <vector>

using namespace std;

int main()
{
    MyBST arbol;
    vector<int> valores = {21,13,33,10,18,25,40,29,27,30};

    for (int x : valores)
    {
        arbol.insert(x);
    }

    cout << "Preorden: " << endl;
    arbol.preorden();
    cout << endl << endl;

    cout << "Inorder: " << endl;
    arbol.inorder();
    cout << endl << endl;

    cout << "Postorder: " << endl;
    arbol.postorder();
    cout << endl << endl;

    cout << "Level: " << endl;
    arbol.level();
    cout << endl << endl;

    cout << endl << "Busqueda de dato: " << arbol.search(13) << endl << endl;

    cout << "Ancestros: " << endl;
    arbol.ancestors(30);
    cout << endl << endl;

    cout << "Level: " << endl;
    cout << arbol.whatLevelAmI(30) << endl;
    cout << endl << endl;
    
    cout << "Height: " << endl;
    cout << arbol.height() << endl << endl;

    arbol.visit(2);
    cout << endl;
    cout << "Se pudo borrar: " << endl;
    cout << arbol.remove(21) << endl;
    arbol.visit(2);
    cout << endl << endl;

    return 0;
}