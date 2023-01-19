#include <iostream>
using namespace std;

class BST{
    int data;
    BST *left,*right;
public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST* Insert(BST*, int);
};

// Default constructor definition.
BST::BST(){
    data = 0;
    left = right = NULL;
}

// Parameterized constructor definition.
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
    BST binaryTree, *root = NULL;
    int n=0;
    while (n<6) {
        cout << "\nEnter Your Choice \n";
        cout << "Enter 1 To create BST \n";
        cout << "Enter 2 To serach the node \n";
        cout << "Enter 3 To find the no. of internal nodes \n";
        cout << "Enter 4 To find the no. of external nodes \n";
        cout << "Enter 5 To find the no. of internal links \n";
        cout << "Enter 6 To find the no. of external links \n";
        cout << "Enter 0 To terminate the program \n";
        cin>>n;
        
        switch (n) {
            case 1:	  
            cout << "BST is being created... \n";
            root = binaryTree.Insert(root, 10);
            binaryTree.Insert(root, 8);
            binaryTree.Insert(root, 12);
            binaryTree.Insert(root, 4);
            binaryTree.Insert(root, 11);
            binaryTree.Insert(root, 15);
            binaryTree.Insert(root, 6);
            binaryTree.Insert(root, 17);
            binaryTree.Insert(root, 7);
            binaryTree.Insert(root, 9);
            binaryTree.Insert(root, 16);
            cout << "Done. \n";
            break;
            
            case 2:
            break;			 
            
            case 3:
            break;

            case 4:
            break;	

            case 5:
            break;	

            case 6:
            break;			 
            
            default :
            break;
        }
    }

    return 0;
}