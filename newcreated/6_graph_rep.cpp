#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

// using adjecency matrix representation

// int main()
// {
//     int v, e;
//     cout<<"\nEnter no of vertices : ";
//     cin>>v;
//     // cout<<"\nEnter no of edges: ";
//     // cin>>e;
//     int gp[v][v];

//     for(int i = 0; i< v; i++)
//     {
//         for(int j = 0; j < v; j++)
//         {
//             cout<<"\nEdge from vertex "<<i<<" to "<<" vertex "<<j<<" present  (1 or 0) : ";
//             cin>>gp[i][j];
//         }
//     }
//     for(int i = 0; i< v; i++)
//     {
//         for(int j = 0; j < v; j++)
//         {
//             cout<<"\nEdge from vertex "<<i<<" to "<<" vertex "<<j<<" present  (1 or 0) : ";
//             cin>>gp[i][j];
//         }
//     }
    


//     return 0;
// }



// using adjecency list representation
void dfsUtil(vector<vector<int>>& g, int v, vector<bool> & visited)
{
    visited[v] = true;
    cout<<v<<" ";
    for(int x: g[v])
    {
          while (!visited[x])
    {
        dfsUtil(g, x, visited);
    }
    
    }
  
}
void dfs(vector<vector<int>>& g, int start)
{
    vector<bool> visited(g.size(), false);
    dfsUtil(g, start, visited);
}


void bfs(vector<vector<int>> & g, int start)
{
    vector<bool> visited(g.size(), false);
    queue<int> q; 
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int x : g[v])
        {
            if(!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

}

int main()
{
    int v, e , s, d;
    cout<<"\nenter how many vetex: ";
    cin>>v;
    cout<<"\nHow many edges: ";
    cin>> e;
    vector<vector<int>> g(v);
    for(int i = 0 ; i< e; i++)
    {
        cout<<"\nEnter edges (like 1->2 u can write 1 2): ";
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    
   bfs(g, 0);
cout<<endl;
dfs(g, 0);

    return 0;
}


