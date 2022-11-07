// Act 4.1 - Grafo: sus representaciones y sus recorridos
// Diego Curiel Castellanos - A01640372

#include "MyGraph.h"
#include <iostream>
#include <vector>

using namespace std;

MyGraph::MyGraph(vector<vector<int>> &matriz)
{
    loadGraph(matriz);
}

void MyGraph::loadGraph(vector<vector<int>> &matriz)
{
    this->matriz = matriz;
}