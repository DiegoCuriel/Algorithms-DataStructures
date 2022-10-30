/*
Descripción: Act 2.3 - Actividad Integral estructura de datos lineales 
(Evidencia Competencia)

Autores:
Carlos David Amezcua Canales - A01641742
Alexia Giselle Paz Jasso - A01635557
Diego Curiel Castellanos - A01640372

Fecha: 11/10/2022
*/

#include <iostream>
#include <fstream>
#include "MyLinkedList.h"

using namespace std;

int main()
{
    /*
    Recibimos la bitácora y almacenamos cada dato dentro de una lista ligada
    A esta lista ligada le aplicamos mergeSort y escribimos los datos
    ordenados de menor a mayor, por Ip, a la bitácora ordenada
    */

    ifstream entrada("bitacora.txt");
    MyLinkedList bitacora;
    Registro aux;
    while (entrada >> aux)
    {
        bitacora.insertLast(aux);
    }
    entrada.close();

    bitacora.mergeSort();
    
    ofstream salida("bitacoraOrdenadaIP-Eq3.txt");
    salida << bitacora;
    salida.close();

    /*
    Menú de búsqueda para rango de registros en bitácora
    Se busca un rango de registros a partir de 2 ip's dadas
    */

    string opcion;
    int numeroDeConsulta = 1;
    do
    {
        system("clear");
        cout << "##### SISTEMA DE BÚSQUEDAS SOBRE LA BITÁCORA #####" << endl;
        cout << endl;
        cout << "[!] Introduzca el rango de búsqueda." << endl;
        cout << endl;

        cout << "Primera IP (XXX.XXX.XXX.XXX): ";
        string c0, c1, c2, c3, c4 = "0";
        getline(cin, c0, '.');
        getline(cin, c1, '.');
        getline(cin, c2, '.');
        getline(cin, c3);
        Ip primeraIp = Ip(stoi(c0), stoi(c1), stoi(c2), stoi(c3), stoi(c4));

        cout << "Ultima IP  (XXX.XXX.XXX.XXX): ";
        c4 = "999999";
        getline(cin, c0, '.');
        getline(cin, c1, '.');
        getline(cin, c2, '.');
        getline(cin, c3);
        Ip ultimaIp = Ip(stoi(c0), stoi(c1), stoi(c2), stoi(c3), stoi(c4));

        cout << endl;
        cout << "Resultados de búsqueda:" << endl;
        cout << endl;

        ofstream salida("salida" + to_string(numeroDeConsulta++) + "-Eq3.txt");
        bitacora.consulta(salida, Registro(primeraIp), Registro(ultimaIp));
        salida.close();
        cout << endl;

        cout << "[!] Presione enter para continuar o teclee \"exit()\" para salir." << endl;
        getline(cin, opcion, '\n');
    }
    while (opcion != "exit()");

    return 0;
}
