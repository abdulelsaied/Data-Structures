// Name: Abdul El-Saied
// CIS 25 IN-CLASS DAY 27
// 11/26/2019
// This program implements various functions relating to binary search trees, and tests them in the main function.

#include <iostream>

using namespace std;

struct BSTnode {
    int data;
    BSTnode *left;
    BSTnode *right;

};

BSTnode *addNode(BSTnode *root, int value);
bool containsValue(BSTnode *root, int value);
void printInOrder(BSTnode *root);
void deleteTree(BSTnode *root);


int main() {

    BSTnode *root = nullptr;

    root = addNode(root, 1);
    root = addNode(root, 3);
    root = addNode(root, 5);
    root = addNode(root, 8);
    root = addNode(root, -11);
    root = addNode(root, -15);
    root = addNode(root, -10);

    cout << "the tree in order: ";
    printInOrder(root);
    cout << endl;

    cout << containsValue(root, -15) << endl;
    cout << containsValue(root, 137) << endl;
    
    deleteTree(root);
    root = nullptr;
    printInOrder(root);
    
}

// adds a node to the BST
BSTnode *addNode(BSTnode *root, int value){
    if (root == nullptr){
        root = new BSTnode;
        root->left = nullptr;
        root->right = nullptr;
        root->data = value;
        return root;
    }
    if (value < root->data){
        root->left = addNode(root->left, value);
        return root;
    }
    if (value > root->data){
        root->right = addNode(root->right, value);
        return root;
    }
    return root;
}


// returns true if the tree contains value, false otherwise
bool containsValue(BSTnode *root, int value){
    if(root == nullptr){
        return false;
    }
    else if(root->data == value){
        return true;
    }
    else{
        return containsValue(root->left, value) || containsValue(root->right, value);
    }
}

//prints the binary search tree in order (least to greatest)
void printInOrder(BSTnode *root){
    if(root == nullptr){
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);

}

// deletes entire BST
void deleteTree(BSTnode *root) {
    if(root == NULL){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
