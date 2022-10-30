// Actividad 1.1 - Funciones iterativas, recursivas y su análisis de complejidad
// Diego Curiel Castellanos - A01640372

#include <iostream>

using namespace std;

int sumaIternativa(int n) //Metodo iterativo - Complejidad: O(n)
{
    int suma;
    for (int i = 1; i <= n; i++)
    {
        suma += i;
    }
    return suma;
}

int sumaRecursiva(int n) //Metodo recursivo - Complejidad: O(n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sumaRecursiva(n - 1);
    }
}

int sumaDirecta(int n) //Metodo directo - Complejidad: O(1)
{
    int res = (n * (n + 1)) / 2;
    return res;
}

int main() //Main que calcula la sumatoria de 1 hasta n llamando a 3 funciones.
{
    cout << "Actividad 1.1 - Funciones iterativas, recursivas y su análisis de complejidad" << endl;
    
    cout << endl << "Introduce n: " << endl;
    int numero;
    cin >> numero;

    cout << endl << "Sumatoria con metodo iterativo:" << endl;
    cout << sumaIternativa(numero) << endl;

    cout << endl << "Sumatoria con metodo recursivo:" << endl;
    cout << sumaRecursiva(numero) << endl;

    cout << endl << "Sumatoria con el metodo matemático:" << endl;
    cout << sumaDirecta(numero) << endl;

    return 0;
}