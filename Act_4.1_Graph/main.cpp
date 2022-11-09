// Act 4.1 - Grafo: sus representaciones y sus recorridos
// Diego Curiel Castellanos - A01640372

#include <iostream>
#include <vector>
#include "MyGraph.h"

using namespace std;

int main()
{
    vector<vector<int>> matriz = {{0, 1, 1, 0, 0},
                                  {1, 0, 0, 1, 0},
                                  {1, 0, 0, 0, 0},
                                  {0, 1, 0, 0, 1},
                                  {0, 0, 0, 1, 0}};
    
    MyGraph graph(matriz);

    cout << "Recorrido DFS:" << endl;
    graph.DFS(0);

    cout << endl <<  endl;

    cout << "Recorrido BFS:" << endl;
    graph.BFS(0);

    return 0;
}