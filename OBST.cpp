// #include<bits/stdc++.h>
// using namespace std;

// // 8

// void printMatrix(vector<vector<int>>& mat){
//     for(auto v : mat) {
//         for(auto i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }

// int optimalBST(vector<int>& p, vector<int>& q, int n){

//     cout << endl;

//     vector<vector<int>> W(n+1, vector<int>(n+1, -1));
//     vector<vector<int>> C(n+1, vector<int>(n+1, -1));

//     // W[i][i] = q[i]
//     for(int i=0; i<=n; i++){
//         W[i][i] = q[i];
//     }

//     // C[i][i] = 0;
//     for(int i=0; i<=n; i++){
//         C[i][i] = 0;
//     }

//     for(int diagonal=1; diagonal<=n; diagonal++){

//         for(int i=0, j=diagonal; i<=n && j<=n; i++, j++){

//             W[i][j] = W[i][j - 1] + p[j] + q[j];

//             // minCost = min( all C[i][x] + C[x+1][j] ) where x = i to j-1
//             int minCost = INT_MAX;
//             for(int x=i; x<j; x++){
//                 minCost = min(minCost, C[i][x] + C[x+1][j]);
//             }

//             C[i][j] = minCost + W[i][j];
//         }
//     }

//     // printMatrix(C);
//     // cout << endl;
//     // printMatrix(W);

//     return C[0][n];
// }


// int main(){
    
//     int n;
//     cout << "Enter No of Nodes in OBST: ";
//     cin >> n;

//     vector<int> p(n + 1), q(n + 1);

//     // p[1] to p[n]
//     cout << "Enter P[1...n]: ";
//     for(int i=1; i<=n; i++){
//         cin >> p[i];
//     }

//     // q[0] to q[n]
//     cout << "Enter Q[0...n]: ";
//     for(int i=0; i<=n; i++){
//         cin >> q[i];
//     }

//     cout << "Minimum cost of OBST: " << optimalBST(p, q, n) << endl;

//     return 0;
// }


#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 10;
class Node
{
private:
    int data;
    Node * left;
    Node * right;
public:
    Node(int value = 0)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class OBST;
};
class OBST
{
    private:
        int N; //Number of Keys
        int a[MAX];
        float p[MAX];
        float q[MAX];
        float W[MAX][MAX];
        float C[MAX][MAX];
        int R[MAX][MAX];
        Node *root;
    public:
        OBST(int n = 0)
        {
            root = NULL;
            N = n+1;
            for (int i=0;i<N;i++)
            {
                a[i] = 0;
                p[i] = 0;
                q[i] = 0;
                for(int j = 0;j<N;j++)
                 {
                     W[i][j] = 0;
                     C[i][j] = 0;
                     R[i][j] = 0;
                 }
            }
        }
        void read()
        {
            cout<<"Enter the key values "<<endl;
            int i;
            for (i=1;i<N;i++)
            {
                cout<<"a[ "<<i<<" ] = ";
                cin>>a[i];
            }
            cout<<"Enter the Success Probabilities values "<<endl;
            for (i=1;i<N;i++)
            {
                cout<<"p[ "<<i<<" ] = ";
                cin>>p[i];
            }
            cout<<"Enter the Failure Probabilities values "<<endl;
            for (i=0;i<N;i++)
            {
                cout<<"q[ "<<i<<" ] = ";
                cin>>q[i];
            }
        }
        void display()
        {
            int i;
            cout<<"a = { ";
            for (i=0;i<N;i++)
               cout<<setw(3)<<a[i]<<" , ";
            cout<<"\b\b}"<<endl;
            cout<<"p = { ";
            for (i=0;i<N;i++)
               cout<<setw(3)<<p[i]<<" , ";
            cout<<"\b\b}"<<endl;
            cout<<"q = { ";
            for (i=0;i<N;i++)
               cout<<setw(3)<<q[i]<<" , ";
            cout<<"\b\b}"<<endl;
        }
        void display_obst()
        {
            int i,j;
            cout<<"W = { "<<endl;
            for (i=0;i<N;i++)
            {
                cout<<"      ";
                for (j=0;j<N;j++)
                {
                    cout<<setw(3)<<W[i][j]<<" , ";
                }
                cout<<"\b\b "<<endl;
            }
            cout<<"     }"<<endl;

            cout<<"C = { "<<endl;
            for (i=0;i<N;i++)
            {
                cout<<"      ";
                for (j=0;j<N;j++)
                {
                    cout<<setw(3)<<C[i][j]<<" , ";
                }
                cout<<"\b\b "<<endl;
            }
            cout<<"     }"<<endl;

            cout<<"R = { "<<endl;
            for (i=0;i<N;i++)
            {
                cout<<"      ";
                for (j=0;j<N;j++)
                {
                    cout<<setw(3)<<R[i][j]<<" , ";
                }
                cout<<"\b\b "<<endl;
            }
            cout<<"     }"<<endl;
        }
        void Construct_obst()
        {
            int i=0,j=0;
            float new_cost,min_cost = 0.0;

            int k,min_k;


            for(i = 0; i<N ;i++)
            {
                //Optimal Trees with zero number of Nodes
                W[i][i] = q[i];
                C[i][i] = 0;
                R[i][i] = 0;
                //Optimal Trees with one number of Nodes
                W[i][i+1] = W[i][i] + p[i+1] + q[i+1];
                C[i][i+1] = W[i][i+1];
                R[i][i+1] = i+1;
            }
            int m;
            for(m = 2; m<=N ; m++ )
            {//Optimal Trees with m number of Nodes
                for(i=0;i<N-m; i++)
                {
                    j =i+m;
                    W[i][j] = W[i][j-1]+ p[j] + q[j];

                    min_cost = 9999;
                    min_k = i+1;
                    for(k=i+1 ; k<=j; k++)
                    {
                        new_cost = C[i][k-1] +C[k][j];
                        if( new_cost < min_cost)
                        {
                          min_cost = new_cost;
                          min_k = k;
                        }
                    }
                    C[i][j] = min_cost+W[i][j];
                    R[i][j] = min_k;
                }

            }
        }
        Node* build_obst(int i, int j)
        {
            int index,key;
            Node *pNew;
            if(R[i][j] == 0)
                return NULL;
            else
            {

                cout<<"i = "<<i<<" j = "<<j<<" ->"<<a[R[i][j]]<<endl;
                index = R[i][j];
                key = a[index];
                pNew = new Node(key);
                pNew->left = build_obst(i,R[i][j]-1);
                pNew->right = build_obst(R[i][j],j);
                return pNew;
            }
        }
        void build_obst()
        {
            if(root == NULL)
            {
                cout<<"Build started";

                root = build_obst(0,N-1);
            }

        }
        void inorder(Node *root)
        {
            if(root!=NULL)
            {
                inorder(root->left);
                cout<<root->data<<" ";
                inorder(root->right);
            }
        }
        void inorder()
        {
            inorder(root);
        }
};

int main()
{
    int n;
    cout<<"Enter number of keys : ";
    cin>>n;
    OBST b(n);
    b.read();
    b.Construct_obst();
    b.display();
    b.display_obst();
    b.build_obst();
    b.inorder();
    return 0;
}