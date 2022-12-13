/*
Act 5.2 - Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)

Autores:
Carlos David Amezcua Canales - A01641742
Alexia Giselle Paz Jasso - A01635557
Diego Curiel Castellanos - A01640372

Fecha: 30/11/2022
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include "Registro.h"
#include "MyHashTable.h"

using namespace std;

int main()
{
    ifstream entrada("bitacora3-1.txt");
    MyHashTable g;
    Registro registro;
    while (entrada >> registro)
    {
        g.put(registro.getIp(), registro.getFecha());
    }
    entrada.close();

    string respuesta;
    do
    {
        system("clear");
        cout << "Introduzca una IP para consultar las fechas de sus accesos" << endl;
        cout << "[XXX.XXX.XXX.XXX]: ";
        
        Ip ip;
        getline(cin, respuesta, '.');
        ip.setC0(std::stoi(respuesta));
        getline(cin, respuesta, '.');
        ip.setC1(std::stoi(respuesta));
        getline(cin, respuesta, '.');
        ip.setC2(std::stoi(respuesta));
        getline(cin, respuesta);
        ip.setC3(std::stoi(respuesta));
        ip.setC4(0);

        multiset<Fecha> ans = g.get(ip);
        cout << endl;
        cout << ip.getIp() << endl;
        cout << endl;
        cout << "---- INICIO de la consulta ----" << endl;
        for (auto i : ans)
        {
            cout << i << endl;
        }
        cout << "---- FIN de la consulta -------" << endl;
        cout << endl;
        cout << "¿Desea realizar otra consulta? [Y / N]: ";
        cin >> respuesta;
    }
    while(respuesta == "Y");

    return 0;
}
