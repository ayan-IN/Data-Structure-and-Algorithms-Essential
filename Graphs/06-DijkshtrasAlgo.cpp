#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }
    void addEdge(int i, int j, int weight, bool undir = true)
    {
        l[i].push_back({weight, j});
        if (undir)
            l[j].push_back({weight, i});
    }
    int dijkshtra(int src, int dest)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;
        dist[src] = 0;
        s.insert({0, src});
        while (!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);

            // Iterate over the neighbours
            for(auto nbrPair:l[node])
            {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;
                if(distTillNow+currentEdge<dist[nbr])
                {
                    //Remove if the nbr is already present in the set
                    auto f = s.find({dist[nbr], nbr});
                    if(f!=s.end())
                        s.erase(f);
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        for (int i = 0; i < V;i++)
        {
            cout << "Node " << i << " ---> " << dist[i] << " unit"<<endl;
        }
        return dist[dest];
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);
    cout << g.dijkshtra(0, 4);
    return 0;
}