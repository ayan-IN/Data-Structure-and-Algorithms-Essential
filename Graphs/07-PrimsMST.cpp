#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>
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
        if (undir == true)
        {
		    l[j].push_back({weight, i});
        }
	}
	
    void primMST()
    {
		priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
		
		int src = 0;
		
		vector<int> key(V, INT_MAX);
		key[src] = 0;
		
		vector<int> parent(V, -1);
		
		vector<bool> inMST(V, false);
		
		pq.push(make_pair(0, src));
		
		while (!pq.empty())
		{
			auto it = pq.top();
			int u = it.second;
			pq.pop();
			
			if(inMST[u] == true)
			{
				continue;
			}
			
			inMST[u] = true;
			
			for (auto nodes : l[u])
			{
				int weight = nodes.first;
				int v = nodes.second;
				
				if (inMST[v] == false && key[v] > weight)
				{
					key[v] = weight;
					parent[v] = u;
					pq.push(make_pair(key[v], v));
				}
			}
		}
		for (int i = 1; i < V; ++i)
		{
			cout << parent[i] << " ---> " << i << endl;
		}
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
    g.primMST();
    return 0;
}