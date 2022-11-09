// Act 4.1 - Grafo: sus representaciones y sus recorridos
// Diego Curiel Castellanos - A01640372

#include "MyGraph.h"
#include <iostream>
#include <vector>

using namespace std;

MyGraph::MyGraph(vector<vector<int>> &matriz)
{
    loadGraph(matriz);
    this->visitado = vector<bool>(matriz.size(), false);
}

void MyGraph::loadGraph(vector<vector<int>> &matriz)
{
    this->matriz = matriz;
}

void MyGraph::DFS(int nodoIni)
{
    DFS(nodoIni, this->visitado);
}

void MyGraph::DFS(int nodoIni, vector<bool> &visitado)
{
    visitado[nodoIni] = 1;
    cout << nodoIni << ",";
    for (int i = 0; i < this->matriz.size(); i++)
    {
        if (this->matriz[nodoIni][i] && !visitado[i])
        {
            DFS(i, visitado);
        }
    }
}