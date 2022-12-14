// Act 4.1 - Grafo: sus representaciones y sus recorridos
// Diego Curiel Castellanos - A01640372

#include "MyGraph.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

MyGraph::MyGraph(vector<vector<int>> &matriz) // O(1)
{
    loadGraph(matriz);
}

void MyGraph::loadGraph(vector<vector<int>> &matriz) // O(n^2)
{
    this->matriz = matriz;
}

void MyGraph::DFS(int nodoIni) // O(n)
{
    vector<bool> visitado(this->matriz.size(), false);
    DFS(nodoIni, visitado);
}

void MyGraph::DFS(int nodoIni, vector<bool> &visitado) // O(V^2), V = numero de vertices - podríamos mejorar esta complejidad con una lista de adyacencia
{
    visitado[nodoIni] = true;
    cout << nodoIni << ",";
    for (int i = 0; i < this->matriz.size(); i++)
    {
        if (this->matriz[nodoIni][i] && !visitado[i])
        {
            DFS(i, visitado);
        }
    }
}

void MyGraph::BFS(int nodoIni) // O(V^2), V = numero de vertices - podríamos mejorar esta complejidad con una lista de adyacencia
{
    vector<bool> visitado(this->matriz.size(), false);
    queue<int> cola;
    cola.push(nodoIni);
    visitado[nodoIni] = true;
    while (!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();
        cout << nodo << ",";
        for (int i = 0; i < this->matriz.size(); i++)
        {
            if (this->matriz[nodo][i] && !visitado[i])
            {
                cola.push(i);
                visitado[i] = true;
            }
        }
    }
}