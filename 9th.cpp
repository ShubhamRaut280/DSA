#include <bits/stdc++.h>
using namespace std;

// 9

// AVL Node
class Node {
    public:
    string data;
    Node* left;
    Node* right;
    int balanceFactor;

    Node(string d) {
        data = d;
        left = NULL;
        right = NULL;
        balanceFactor = 0;
    }
};

class AVLTree {
    
    private:
    Node* root;

    public:
    AVLTree() {
        root = NULL;
    }

    void insert(string data) {
        root = insertNode(root, data);
    }

    bool search(string& data) {
        return searchNode(root, data);
    }

    void deleteNode(string& data) {
        root = deleteNode(root, data);
    }

    void printSorted() {
        cout << "Sorted: ";
        inorder(this->root);
        cout << endl;
    }

    private:
    Node* insertNode(Node* node, string& data) {

        if(node == NULL){
            return new Node(data);
        }

        // Find location to insert
        if(data < node->data){
            node->left = insertNode(node->left, data);
        } 
        else if(data > node->data){
            node->right = insertNode(node->right, data);
        } 
        else {
            return node;
        }

        // Update balance factor
        node->balanceFactor = getHeight(node->left) - getHeight(node->right);

        // Perform rotations if necessary
        if(node->balanceFactor > 1) {
            if(data < node->left->data){ // Right Rotation
                node = rotateRight(node);
            } 
            else { // LR Rotation
                node->left = rotateLeft(node->left);
                node = rotateRight(node);
            }
        } 
        else if(node->balanceFactor < -1){
            if(data > node->right->data) { // Left Rotation
                node = rotateLeft(node);
            } 
            else { // RL Rotation
                node->right = rotateRight(node->right);
                node = rotateLeft(node);
            }
        }

        return node;
    }

    bool searchNode(Node* node, string& data) {

        if(node == NULL){
            return false;
        }

        if(data == node->data){
            return true;
        } 
        else if(data < node->data){
            return searchNode(node->left, data);
        } 
        else {
            return searchNode(node->right, data);
        }
    }

    Node* deleteNode(Node* node, string& data) {

        if(node == NULL) {
            return node;
        }

        if(data < node->data) {
            node->left = deleteNode(node->left, data);
        } 
        else if(data > node->data) {
            node->right = deleteNode(node->right, data);
        } 
        else {
            // Found the node to delete

            // Case 1: Node has no children or only one child
            if(node->left == NULL || node->right == NULL){
                Node* temp = node->left ? node->left : node->right;

                // No child case
                if(temp == NULL){
                    temp = node;
                    node = NULL;
                } 
                else {
                    // One child case
                    *node = *temp;
                }

                delete temp;
            } 
            else {
                // Case 2: Node has two children
                Node* temp = findMinNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        // If the tree had only one node
        if(node == NULL){
            return node;
        }

        // Update balance factor
        node->balanceFactor = getHeight(node->left) - getHeight(node->right);

        // Perform rotations if necessary
        if(node->balanceFactor > 1){
            if(getHeight(node->left->left) >= getHeight(node->left->right)) { // Right Rotation
                node = rotateRight(node);
            } 
            else { // LR Rotation
                node->left = rotateLeft(node->left);
                node = rotateRight(node);
            }
        } 
        else if(node->balanceFactor < -1){
            if (getHeight(node->right->right) >= getHeight(node->right->left)) { // Left Rotation
                node = rotateLeft(node);
            } 
            else { // RL Rotation
                node->right = rotateRight(node->right);
                node = rotateLeft(node);
            }
        }

        return node;
    }

    void inorder(Node* node){

        if(node == NULL)
            return;

        inorder(node->left);

        cout << node->data << " ";

        inorder(node->right);
    }

    Node* findMinNode(Node* node) {
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }

    int getHeight(Node* node) {
        if(node == NULL){
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    Node* rotateLeft(Node* node) {
        
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        // Update balance factors
        node->balanceFactor = getHeight(node->left) - getHeight(node->right);
        newRoot->balanceFactor = getHeight(newRoot->left) - getHeight(newRoot->right);

        return newRoot;
    }

    Node* rotateRight(Node* node) {

        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        node->balanceFactor = getHeight(node->left) - getHeight(node->right);
        newRoot->balanceFactor = getHeight(newRoot->left) - getHeight(newRoot->right);

        return newRoot;
    }
};

int main() {

    AVLTree avlTree;

    int choice = -1;
    bool found = 0;
    string word = "";

    while(choice != 5){
        cout << "************* MENU *************\n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Delete Word\n";
        cout << "4. Print Dictionary in Sorted Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter word to Insert: ";
                cin >> word;
                avlTree.insert(word);
                cout << "Word Added successfully.";
                break;
            case 2:
                cout << "Enter word to Search: ";
                cin >> word;
                found = avlTree.search(word);
                if(found) {
                    cout << "Value found in the AVL tree.";
                } 
                else {
                    cout << "Value not found in the AVL tree.";
                }
                break;
            case 3:
                cout << "Enter word to Delete: ";
                cin >> word;
                found = avlTree.search(word);
                if(found) {
                    avlTree.deleteNode(word);
                    cout << "Word Deleted successfully.";
                } 
                else {
                    cout << "Value not found in the AVL tree.";
                }
                break;
            case 4:
                avlTree.printSorted();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid Choice.";
                break;
        }
        cout << "\n\n";
    }

    return 0;
}
