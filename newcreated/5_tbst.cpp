#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    bool lthread;
    bool rthread;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        this->lthread = false;
        this->rthread = false;
    }
};
void getInorder(node *root, vector<node *> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    getInorder(root->left, inorder);
    inorder.push_back(root);
    getInorder(root->right, inorder);
}

bool ispresent(node*root, int d)
{
    if (root==NULL)
    {
        return false;
    }
    if (d>root->data)
    {
        return ispresent(root->right, d);
    }
    if (d<root->data)
    {
        return ispresent(root->left, d);
    }

    if (d==root->data)

    {
            return true;
    }
    

    return false;
    
    
    
}

class tbst
{
public:
    node *root;
    bool isthreaded;
    vector<node *> inorder;

    tbst()
    {
        this->root = NULL;
        this->isthreaded = false;
    }

    void insert(int d)
    {
        root = insertU(root, d);
    }

    node *insertU(node *root, int d)
    {
        if (root == NULL)
        {
            root = new node(d);
            return root;
        }

        if (d > root->data)
        {
            root->right = insertU(root->right, d);
        }
        if (d < root->data)
        {
            root->left = insertU(root->left, d);
        }

        return root;
    }

    void makeThreaded(node *root)
    {
        vector<node *> inorder;
        getInorder(root, inorder);

        for (int i = 0; i < inorder.size(); i++)
        {
            node *curr = inorder[i];

            if (!curr->left && i - 1 >= 0)
            {
                curr->left = inorder[i - 1];
                curr->lthread = true;
            }

            if (!curr->right && i + 1 < inorder.size())
            {
                curr->right = inorder[i + 1];
                curr->rthread = true;
            }
        }

        isthreaded = true;
    }

    void threadedTraversal()
    {
        if (root == NULL)
        {
            return;
        }
        if (!isthreaded)
        {
            makeThreaded(root);
        }

        node*curr = root;

        // go to leftmost node
        while (curr->left != NULL)
        {
            curr = curr->left;
        }

        // start traversing

        while (curr != NULL)
        {
            cout << curr->data << "  ";
            curr = curr->right;
        }
        cout << endl;
    }
    void search(int d)
    {
        if (ispresent(root, d))
        {
            cout << "value is present..";
        }
        else
        {
            cout << "value not present..";
        }
    }
};

int main()
{
    tbst b;
    vector<node *> inorder;

    int n, a, s;
    cout << "\nEnter how many: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter element: ";
        cin >> a;
        b.insert(a);
    }

    b.threadedTraversal();

    cout<<"\nEnter the value to search : ";
    cin>>s;
    b.search(s);
}