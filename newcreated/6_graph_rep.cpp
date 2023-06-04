#include<iostream>
#include<list>
using namespace std;

// using adjecency matrix representation

int main()
{
    int v, e;
    cout<<"\nEnter no of vertices : ";
    cin>>v;
    // cout<<"\nEnter no of edges: ";
    // cin>>e;
    int gp[v][v];

    for(int i = 0; i< v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout<<"\nEdge from vertex "<<i<<" to "<<" vertex "<<j<<" present  (1 or 0) : ";
            cin>>gp[i][j];
        }
    }
    for(int i = 0; i< v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout<<"\nEdge from vertex "<<i<<" to "<<" vertex "<<j<<" present  (1 or 0) : ";
            cin>>gp[i][j];
        }
    }
    


    return 0;
}


/*

// using adjecency list representation

#include<iostream>
#include<list>
using namespace std;

class graph
{
    int v;
    list<int> *l;
    public: 
    
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int s, int d)
    {
        l[s].push_back(d);
        l[d].push_back(s);
    }
    void print()
    {
        for(int i = 0; i<v; i++)
        {
            cout<<i<<" : ";
          for(int x: l[i])
          {
            cout<<x<<" -> ";
          }
           cout<<endl;
            
        }
    }
};

int main()
{
    int v, e , s, d;
    cout<<"\nenter how many vetex: ";
    cin>>v;
        graph g(v);

    cout<<"\nHow many edges: ";
    cin>> e;
    for(int i = 0 ; i< e; i++)
    {
        cout<<"\nEnter edges (like 1->2 u can write 1 2): ";
        cin>>s>>d;
        g.addEdge(s, d);
    }
    
    g.print();


    return 0;
}

*/