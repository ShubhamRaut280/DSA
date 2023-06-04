#include <iostream>
#include <vector>
#include <queue>
#include<climits>
using namespace std;

struct Edge
{
    int to;
    int w;
};

void print(vector<vector<Edge>> &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << i << " : ";
        for (Edge x : g[i])
        {
            cout << " -> " << x.to;
        }
        cout << endl;
    }
}
void primsMST(vector<vector<Edge>>& g, int start)
{
priority_queue<pair<int, int> , vector<pair< int , int>>, greater<pair<int, int>>> pq;

vector<int> mincost(g.size(), INT_MAX);
vector<int> parent(g.size(), -1);
vector<bool> visited(g.size() , false);
// start with specified node
pq.push(make_pair(0, start));
mincost[start] = 0;

while(!pq.empty())
{
    int u = pq.top().second;
    pq.pop();
    visited[u] = true;
    
    for(auto edge : g[u])
    {
        int v = edge.to;
        int cost = edge.w;

        if(!visited[v] && cost < mincost[v])
        {
            mincost[v] = cost;
            parent[v] = u;
            pq.push(make_pair(cost, v));
        }
    }
}

// for printing 
for(int i = 1; i < g.size(); ++i)
{
    cout<<"office "<<parent[i]<<" to "<<"office "<<i<<" with weight : "<<mincost[i]<<endl;
}

}

int main()
{
    int v, u, w, s, e;
    cout << "\nNo  of vertices of graph: ";
    cin >> v;
    cout << "\nNo of edges of graph: ";
    cin >> u;
    vector<vector<Edge>> graph(v);
    cout << "\nEnter edges start end weight: ";

    for (int i = 0; i < u; i++)
    {
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }
    print(graph);
    
    primsMST(graph, 0);
    return 0;
}
// sample inputs
// 4 
// 5
// 0 1 10 
// 0 2 20
// 0 3 15
// 3 2 32 
// 2 1 47