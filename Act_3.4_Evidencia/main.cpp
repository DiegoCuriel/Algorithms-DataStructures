/*
Descripción: Act 3.4 - Actividad Integral de BST (Evidencia Competencia)

Autores:
Carlos David Amezcua Canales - A01641742
Alexia Giselle Paz Jasso - A01635557
Diego Curiel Castellanos - A01640372

Fecha: 06/11/2022
*/

#include <iostream>
#include <fstream>
#include "Registro.h"
#include "BST.h"

using namespace std;

int main()
{
    int k;
    cout << "Cantidad de ip's con mayor frecuencia a desplegar:" << endl;
    cin >> k;
    ifstream entrada("bitacora.txt");
    BST bst(k);
    Registro prevReg, currReg;
    entrada >> prevReg;
    int frec = 1;
    while (entrada >> currReg)
    {
        if (prevReg.getIp() == currReg.getIp())
        {
            ++frec;
        }
        else
        {
            bst.insert(frec, prevReg.getIp());
            frec = 1;
        }
        prevReg = currReg;
    }
    bst.insert(frec, prevReg.getIp());
    vector<pair<int, Ip>> ans = bst.kMasFrec();
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << i + 1 << ". Frecuencia: " << ans[i].first << ", IP: " << ans[i].second << endl;
    }

    return 0;
}
