#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int getHeight(Node* node){

    if(node == NULL){
        return 0;
    }

    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

void invertTree(Node* root){

    if(root == NULL)
        return;

    swap(root->left, root->right);

    invertTree(root->left);

    invertTree(root->right);
}

class BST {
    Node* root;

    public:
    BST() {
        root = NULL;
    }

    void insert(int d){
        root = insertUtil(root, d);
    }

    bool search(int d){
        return searchUtil(root, d);
    }

    int minValue(){
        if(root == NULL)
            return -1;

        Node* node = root;
        while(node->left != NULL)
            node = node->left;

        return node->data;
    }

    int nodesInLongestPath(){
        return getHeight(root);
    }

    void invert() {
        invertTree(root);
    }

    bool searchUtil(Node* node, int d) {

        if(node == NULL)
            return false;

        if(node->data == d)
            return true;

        if( d < node->data ){
            return searchUtil(node->left, d);
        }
        else {
            return searchUtil(node->right, d);
        }
    }

    Node* insertUtil(Node* node, int d){
    
        // base case
        if(node == NULL){
            node = new Node(d);
            return node;
        }

        if( d > node->data ){
            node->right = insertUtil(node->right, d);
        }
        else {
            node->left = insertUtil(node->left, d);
        }
    }
};

int main() {

    BST t;

    int choice = -1, val = -1;
    bool found = 0;

    while(choice != 6){
        cout << "************* MENU *************\n";
        cout << "1. Insert Value\n";
        cout << "2. Search Value\n";
        cout << "3. Print Minimum Data\n";
        cout << "4. Get Number of Nodes in longest path\n";
        cout << "5. Invert the Binary Search Tree\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter Value to insert: ";
                cin >> val;
                t.insert(val);
                cout << val << " inserted Successfully.";
                break;
            case 2:
                cout << "Enter Value to Search: ";
                cin >> val;
                found = t.search(val);
                if(found) {
                    cout << "Value found in the BST.";
                } 
                else {
                    cout << "Value not found in the BST.";
                }
                break;
            case 3:
                val = t.minValue();
                cout << "Minimum value in BST: " << val;
                break;
            case 4:
                cout << "No of nodes in longest path: " << t.nodesInLongestPath();
                break;
            case 5:
                t.invert();
                cout << "BST inverted, reinvert for other operations to work";
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid Choice.";
                break;
        }
        cout << "\n\n";
    }

    return 0;
}