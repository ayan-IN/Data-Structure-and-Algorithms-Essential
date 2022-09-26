#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    string name;
    list<string> nbrs;
    Node(string name)
    {
        this->name = name;
    }
};
class Graph
{
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }
    void addEdge(string i, string j, bool undir = false)
    {
        m[i]->nbrs.push_back(j);
        if (undir)
            m[j]->nbrs.push_back(i);
    }
    void printAdjList()
    {
        for (auto cityPair : m)
        {
            auto city = cityPair.first;
            cout << city << " ==> ";
            Node *node = cityPair.second;
            for (auto nbr : node->nbrs)
            {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }
};

// Driver Code
int main()
{
    system("cls");
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");
    g.printAdjList();
    return 0;
}