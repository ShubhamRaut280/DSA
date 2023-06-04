#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
int getheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (max(getheight(root->left), getheight(root->right)) + 1);
}

int sval(node *root, int d)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == d)
    {
        return 1;
    }
    if (d > root->data)
    {
        sval(root->right, d);
    }
    if (d < root->data)
    {
        sval(root->left, d);
    }
}

void inTree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    swap(root->left, root->right);
    inTree(root->left);
    inTree(root->right);
}
node *inorderSuc(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}
class BST
{
public:
    node *root;
    BST()
    {
        this->root = NULL;
    }

    void print()
    {
        inorder(root);
    }
    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << "\t" << root->data;
        inorder(root->right);
    }

    void insert(int d)
    {
        root = insertb(root, d);
    }
    node *insertb(node *root, int d)
    {
        if (root == NULL)
        {
            return new node(d);
        }
        if (d > root->data)
        {
            root->right = insertb(root->right, d);
        }
        if (d < root->data)
        {
            root->left = insertb(root->left, d);
        }

        return root;
    }

    void minimum()
    {
        cout << min(root);
    }

    int min(node *root)
    {
        if (root == NULL)
        {
            return -1;
        }

        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }

    void longestP()
    {
        cout << "\nLongest path have " << getheight(root) << " nodes. ";
    }

    void search(int d)
    {
        if (sval(root, d))
        {
            cout << "\nThis value is present.";
        }
        else
        {
            cout << "\nThis value is not present..";
        }
    }

    void invert()
    {
        inTree(root);
    }

    void del(int d)
    {
        root = deleteN(root, d);
    }

    node *deleteN(node *root, int d)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (d < root->data)
        {
            root->left = deleteN(root->left, d);
        }
        else if (d > root->data)
        {
            root->right = deleteN(root->right, d);
        }else{

        // node found

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node *succ = inorderSuc(root->right);
            root->data = succ->data;
            root->right = deleteN(root->right, succ->data);
        }
        }
        return root;
    }
    //     node* deleteN(node* root, int d) {
    //     if (root == NULL) {
    //         return NULL;
    //     }
    //     if (d < root->data) {
    //         root->left = deleteN(root->left, d);
    //     } else if (d > root->data) {
    //         root->right = deleteN(root->right, d);
    //     } else {
    //         // Node found
    //         if (root->left == NULL && root->right == NULL) {
    //             // Case 1: Node with no children
    //             delete root;
    //             return NULL;
    //         } else if (root->left == NULL) {
    //             // Case 2: Node with only right child
    //             node* temp = root->right;
    //             delete root;
    //             return temp;
    //         } else if (root->right == NULL) {
    //             // Case 3: Node with only left child
    //             node* temp = root->left;
    //             delete root;
    //             return temp;
    //         } else {
    //             // Case 4: Node with two children
    //             node* successor = inorderSuc(root->right);
    //             root->data = successor->data;
    //             root->right = deleteN(root->right, successor->data);
    //         }
    //     }
    //     return root;
    // }
};

int main()
{

    BST b;
    int a, d, s;
    cout << "\nEnter how manay ele: ";
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cout << "\nEnter data : ";
        cin >> d;
        b.insert(d);
    }

    b.print();
    cout << "\nMinimum elememnt is : ";
    b.minimum();
    b.longestP();

    cout << "\nEnter the value to be dlete:";
    cin >> s;
    b.del(s);
    b.print();

    cout << "\nEnter the value to be delete:";
    cin >> s;
    b.del(s);
    b.print();

    cout << "\nEnter the value to be dlete:";
    cin >> s;
    b.del(s);
    b.print();

    cout << "\nEnter the value to be delete:";
    cin >> s;
    b.del(s);
    // b.invert();
    b.print();

    return 0;
}
