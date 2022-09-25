// Program to implement adjacency list in graph implementation
#include <iostream>
#include <list>
#include<stdlib.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
            l[j].push_back(i);
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            // Main Node
            cout << i << " ==> ";
            for (auto x : l[i])
                cout << x << ", ";
            cout << endl;
        }
    }
};
// Driver Code
int main()
{
    system("cls");
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.printAdjList();
    return 0;
}