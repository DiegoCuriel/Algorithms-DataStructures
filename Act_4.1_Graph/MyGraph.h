// Act 4.1 - Grafo: sus representaciones y sus recorridos
// Diego Curiel Castellanos - A01640372

#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>

using namespace std;

class MyGraph
{
    private:
        vector<vector<int>> matriz; // Matriz de adyacencia
        void DFS(int nodoIni, vector<bool> &visitado);

    public:
        MyGraph(vector<vector<int>> &matriz);
        void loadGraph(vector<vector<int>> &matriz);
        void DFS(int nodoIni);
        void BFS();
};

#endif // MYGRAPH_H