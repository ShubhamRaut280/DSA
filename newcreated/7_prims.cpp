#include <bits/stdc++.h>
using namespace std;

class data{
    public : 
    int w;
    int node;
    int parent;

    data(int weight, int node, int parent)
    {
        this->w = weight;
        this->node = node;
        this->parent = parent;
    }
};

bool cmpOperator(data d1, data d2)
{
    return (d1.w >= d2.w);
}

struct Edge
{
    int to;
    int w;
};

void print(vector<vector<Edge>> g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout<<":"<<i<<": ";
        for(Edge x : g[i])
        {
            cout<<" -> "<<x.to;
        }
        cout<<endl;
    }
    
}

int main()
{
    int nOffices, nWays, s, e, w;
    cout << "\nhow many offices do you have: ";
    cin >> nOffices;
    cout << "\nHow many ways u have to reach those offices: ";
    cin >> nWays;

    vector<vector<Edge>> graph(nOffices);
    cout << "\nEnter start end and weigth for all edges: ";
    for (int i = 0; i < nWays; i++)
    {
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        graph[e].push_back({s,w});
    }

    print(graph);
    return 0;
}
