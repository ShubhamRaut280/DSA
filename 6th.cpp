#include<iostream>
using namespace std;
class Node
{
private:
    int vertex;
    Node *link;
public:
    Node()
    {
        vertex=0;
        link=NULL;
    }
    Node(int vertex)
    {
        this->vertex=vertex;
        link=NULL;
    }
    friend class Graph;
    friend class Queue;
};
class Queue
{
private:
    Node *front;
    Node *rear;
public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }

    void push(int element)
    {
        Node *newNode=new Node(element);
        if(front==NULL)
        {
            front=newNode;
            rear=newNode;
        }
        else
        {
            rear->link=newNode;
            rear=newNode;
        }
    }

    bool isEmpty()
    {
        if(front==NULL)
        {
            return true;
        }
        return false;
    }

    int Front()
    {
        if(isEmpty())
        {
            return -1;
        }
        return front->vertex;
    }

    void pop()
    {
        if(isEmpty())
        {
            return ;
        }
        else
        {
            if(front->link==NULL)
            {
                delete front;
                front=NULL;
                rear=NULL;
            }
            else
            {
                Node* temp=front->link;
                front->link=NULL;
                delete front;
                front=temp;
            }
        }
    }
    friend class Graph;
};
class Graph
{
private:
    Node* head[100];
    bool visited[100];
    int vertices,edges;
public:
    void create_graph()
    {
        cout<<" Enter the number of vertices of the Graph : ";
        cin>>vertices;
        for(int i=0;i<=vertices;i++)
        {
            head[i]=NULL;
            visited[i]=false;
        }

        cout<<" Enter the number of edges of the Graph : ";
        cin>>edges;
        while(edges--)
        {
            int startVertex,endVertex;
            cout<<" Enter an edge (startVertex,endVertex) : ";
            cin>>startVertex>>endVertex;
            insert_edge(startVertex,endVertex);
            insert_edge(endVertex,startVertex);
        }
    }
    void insert_edge(int startVertex,int endVertex)
    {
        Node *newNode=new Node(endVertex);
        if(head[startVertex]==NULL)
        {
            head[startVertex]=newNode;
        }
        else
        {
            Node *temp=head[startVertex];
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newNode;
        }
    }

    void display_graph()
    {
        for(int i=1;i<=vertices;i++)
        {
            cout<<i<<" -> ";
            Node *temp=head[i];
            while(temp!=NULL)
            {
                cout<<temp->vertex;
                if(temp->link!=NULL)
                {
                    cout<<" , ";
                }
                temp=temp->link;
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void DFS(int vertex)
    {
        cout<<vertex<<" ";
        visited[vertex]=true;

        Node *temp=head[vertex];
        while(temp!=NULL)
        {
            vertex=temp->vertex;
            if(!visited[vertex])
            {
                DFS(vertex);
            }
            temp=temp->link;
        }
    }
    void DFS()
    {
        int vertex;
        cout<<" Enter the starting vertex for DFS : ";
        cin>>vertex;

        cout<<" The Depth First Traversal (DFS) of the Graph is : ";
        DFS(vertex);

        for(int i=1;i<=vertices;i++)
        {
            visited[i]=false;
        }
    }

    void BFS(int vertex)
    {
        Queue queue;
        queue.push(vertex);
        visited[vertex]=true;
        while(!queue.isEmpty())
        {
            int current=queue.Front();
            cout<<current<<" ";
            queue.pop();
            Node* temp=head[current];
            while(temp!=NULL)
            {
                current=temp->vertex;
                if(!visited[current])
                {
                    queue.push(current);
                    visited[current]=true;
                }
                temp=temp->link;
            }
        }
    }
    void BFS()
    {
        int vertex;
        cout<<" Enter the starting vertex for BFS ";
        cin>>vertex;

        cout<<" The Breadth First Traversal (BFS) of the Graph is : ";
        BFS(vertex);

        for(int i=1;i<=vertices;i++)
        {
            visited[i]=false;
        }
    }
};
int main()
{
    Graph obj;
    int option;
    do{
        cout<<"-------------------Menu-------------------"<<endl;
        cout<<" 1. Create a Graph "<<endl;
        cout<<" 2. Display the Graph "<<endl;
        cout<<" 3. Depth First Traversal (DFS) of the Graph "<<endl;
        cout<<" 4. Breath First Traversal (BFS) of the Graph "<<endl;
        cout<<" 5. Exit "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        switch(option)
        {
        case 1:
            obj.create_graph();
            break;
        case 2:
            obj.display_graph();
            break;
        case 3:
            obj.DFS();
            break;    
        case 4:
            obj.BFS();
            break;    
        case 5:
            exit(0);        
        }
        cout<<endl;

    }while(option>=1 && option<=4);
    return 0;
}