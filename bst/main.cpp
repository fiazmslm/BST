#include <iostream>
using namespace std;

class BST{
    int data;
    BST *left,*right;
public:
    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST* Insert(BST*, int);
};

// Parameterized Constructor definition.
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST::Insert(BST* root,int value){
    BST* newNode = new BST(value);

    // First case for root.
    if(!root){
        return newNode;
    }

    if(value>root->data){
        // Right case: when new value is greater.
        root->right = Insert(root->right, value);
    }
    else if (value < root->data){
        // Left case: when new value is smaller.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}

int main(){
    cout<<"Hello World";
}