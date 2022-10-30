/*
Descripción: Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos 
Fundamentales (Evidencia Competencia)

Autores:
Carlos David Amezcua Canales - A01641742
Alexia Giselle Paz Jasso - A01635557
Diego Curiel Castellanos - A01640372

Fecha: 14/09/2022
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "Registro.h"

using namespace std;

int primerMayorOIgual(vector<Registro> &v, Registro x) {
    /*
    Descripción: Función que busca con la busqueda binaria el primer dato mayor
    o igual.

    Parámetros: El vector <Registro> ordenado del espacio de búsqueda y el dato 
    Registro del que se desea buscar el primer mayor o igual.

    Valor de retorno: El índice donde se encuentra el primer mayor o igual o 
    el tamaño del vector en caso de que no exista.

    Precondición: El vector<Registro> debe contener los n registros ordenados en 
    forma ascenedente por fecha.

    postcondición: Ninguna.

    Complejidad: O(log(n))
    */
    int mayorPaso = 1;
    while (mayorPaso < v.size()) mayorPaso *= 2;
    int pos = 0;
    for (int paso = mayorPaso; paso > 0; paso /= 2) {
        if (pos + paso < v.size() && v[pos + paso] < x) {
            pos += paso;
        }
    }
    if (v[pos] < x) {
        return pos + 1;
    }
    return pos;
}

int primerMayor(vector<Registro> &v, Registro x) {
    /*
    Descripción: Función que busca con la busqueda binaria el primer dato mayor.

    Parámetros: El vector <Registro> ordenado del espacio de búsqueda y el dato 
    Registro del que se desea buscar el primer mayor.

    Valor de retorno: El índice donde se encuentra el primer mayor o el tamaño 
    del vector en caso de que no exista.

    Precondición: El vector<Registro> debe contener los n registros ordenados en 
    forma ascenedente por fecha.

    postcondición: Ninguna.

    Complejidad: O(log(n))
    */

    int mayorPaso = 1;
    while (mayorPaso < v.size()) mayorPaso *= 2;
    int pos = 0;
    for (int paso = mayorPaso; paso > 0; paso /= 2) {
        if (pos + paso < v.size() && v[pos + paso] <= x) {
            pos += paso;
        }
    }
    if (v[pos] <= x) {
        return pos + 1;
    }
    return pos;
}

void mezcla(vector<Registro> &v, int l, int r) {
    /*
    Descripción: Función auxiliar de "ordenaMerge" que mezcla las soluciones de
    las dos llamadas recursivas.

    Parámetros: Un vector<Registro> con los n registros (como referencia &) y 
    dos números que representan el rango de registros a ordenar.

    Valor de retorno: Nada.

    Precondición: los rangos [l, (l + r) / 2] y [(l + r) / 2 + 1, r] deben estar
    ordenados.

    postcondición: El vector<Rango> contendrá los datos ya ordenados en el rango 
    [l, r].

    Complejidad: O(n) | n = r - l + 1
    */

    int m = (l + r) / 2;
    int p1 = l, p2 = m + 1;
    vector<Registro> vTemp(r - l + 1);
    for (int i = 0; i < vTemp.size(); ++i) {
        if (p1 <= m && p2 <= r) {
            vTemp[i] = v[p1] < v[p2] ? v[p1++] : v[p2++];
        }
        else {
            vTemp[i] = p1 <= m ? v[p1++] : v[p2++];
        }
    }
    for (int i = 0; i < vTemp.size(); ++i) {
        v[l + i] = vTemp[i];
    }
}

void ordenaMerge(vector<Registro> &v, int l, int r) {
    /*
    Descripción: Función auxiliar de "ordenaMerge".

    Parámetros: Un vector<Registro> con los n registros (como referencia &) y 
    dos registros que representan el rango a ordenar.

    Valor de retorno: Nada.

    Precondición: el rango [l, r] debe estar ordenado.

    postcondición: El vector<Rango> contendrá los datos ya ordenados en el rango 
    [l, r].

    Complejidad: O(n * log(n)) | n = r - l + 1
    */
    if (l < r) {
        int m = (l + r) / 2;
        ordenaMerge(v, l, m);
        ordenaMerge(v, m + 1, r);
        mezcla(v, l, r);
    }
}

void ordenaMerge(vector<Registro> &v) {
    /*
    Descripción: Función que ordena en forma ascendente los datos con el método 
    de Merge.

    Parámetros: Un vector<Registro> con los n numeros (como referencia &).

    Valor de retorno: Nada.

    Precondición: El vector<Registro> debe contener los n registros.

    postcondición: El vector<Registro> contendrá los datos ya ordenados.

    Complejidad: O(n * log(n))
    */

    ordenaMerge(v, 0, v.size() - 1);
}

int main() {
    ifstream entrada("bitacora.txt");

    vector<Registro> bitacora;
    Registro aux;
    while (entrada >> aux) {
        bitacora.push_back(aux);
    }

    entrada.close();

    ordenaMerge(bitacora);

    ofstream salida("bitacoraOrdenada1.3-eq3.txt");

    for (auto i : bitacora) {
        salida << i << endl;
    }

    salida.close();

    system("clear");
    cout << "##### SISTEMA DE BÚSQUEDAS SOBRE LA BITÁCORA #####" << endl;
    cout << endl;
    cout << "[!] Introduzca el rango de búsqueda." << endl;
    cout << endl;
    cout << "Fecha de inicio (Mmm DD HH:MM:SS): ";
    Fecha fechaDeInicio;
    cin >> fechaDeInicio;
    cout << "Fecha de fin    (Mmm DD HH:MM:SS): ";
    Fecha fechaDeFin;
    cin >> fechaDeFin;

    int l = primerMayorOIgual(bitacora, Registro(fechaDeInicio));
    int r = primerMayor(bitacora, Registro(fechaDeFin));

    cout << endl;
    cout << "Resultados de búsqueda:" << endl;
    cout << endl;
    for (int i = l; i < r; ++i) {
        cout << bitacora[i] << endl;
    }

    return 0;
}
