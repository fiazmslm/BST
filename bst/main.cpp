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

    // Search function.
    void Search(BST*,int);

    // Check leaf function.
    bool isLeaf(BST*,int);

    // Get left child function.
    int getLeftChild(BST*,int);

    // Get right child function.
    int getRightChild(BST*,int);

    // Get sibling function.
    int getSibling(BST*, int);

    // Get total internal nodes.
    int internalNodes(BST*);

    // Get total external nodes.
    int externalNodes(BST*);

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

void BST::Search(BST* root,int key) {
    while(root != NULL) {
        if(root->data == key) {
            cout<<"\nyes "<<key<<" is found"<<endl;
            return;
        } 
        else if(root->data > key)
            root = root->left;
        else
            root = root->right;
    }
   cout<<"\nNo "<<key<<" is found"<<endl;
   return;
}

bool BST::isLeaf(BST* root,int key) {
    while(root != NULL) {
        if(root->data == key) {
            if(root->left == NULL && root->right == NULL)
                return true;
            return false;
        } 
        else if(root->data > key)
            root = root->left;
        else
            root = root->right;
    }
   return false;
}

int BST::getLeftChild(BST* root,int key) {
    while(root != NULL) {
        if(root->data == key) {
            if(root->left !=NULL)
                return root->left->data;
            return -1;
        } 
        else if(root->data > key)
            root = root->left;
        else
            root = root->right;
    }
   return -1;
}

int BST::getRightChild(BST* root,int key) {
    while(root != NULL) {
        if(root->data == key) {
            if(root->right !=NULL)
                return root->right->data;
            return -1;
        } 
        else if(root->data > key)
            root = root->left;
        else
            root = root->right;
    }
   return -1;
}


int BST::getSibling(BST* root, int key) 
{
    if (root == NULL || root->data == key) 
    {
      return -1;
    }

    if (root->left != NULL && root->left->data == key) 
    {
        if (root->right!=NULL)
            return root->right->data;
    }
    
    if (root->right != NULL && root->right->data == key) 
    {
      if (root->left!=NULL)
            return root->left->data;
    }

    int temp = getSibling(root->left, key);
    return temp;

    temp = getSibling(root->right, key);
    return temp;
}

int BST::internalNodes(BST *root)
{
    if (root == NULL || (root->left == NULL &&
                         root->right == NULL))
        return 0;
 
    return 1 + internalNodes(root->left) +
               internalNodes(root->right);
}

int BST::externalNodes(BST* root) 
{ 
    if(root == NULL)     
        return 0; 
    if(root->left == NULL && root->right == NULL) 
        return 1;         
    else
        return externalNodes(root->left)+ 
            externalNodes(root->right); 
} 

int main(){
    int data[] = {10,8,12,4,11,15,6,17,7,9,16};
    cout<<"Data\n----------------------\n";
    int dataLength = sizeof(data)/ sizeof(int);
    for(int i=0;i<dataLength;i++){
        cout<<data[i]<<" ";
    }

    BST binaryTree, *root = NULL;
    int n=0,sibling,leftChild,rightChild;
    while (n<6) {
        cout << "\n\nEnter Your Choice \n";
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

                root = binaryTree.Insert(root, data[0]);
                for(int i=1;i<dataLength;i++){
                    binaryTree.Insert(root, data[i]);
                }

                cout << "Done. \n";
            break;
            
            case 2:
                int num;
                cout << "Enter the number you want to search in BST \n";
                cin>>num;

                binaryTree.Search(root,num);
                if(binaryTree.isLeaf(root,num)){
                    cout << "Yes, it is a leaf node \n";
                }else{
                    cout << "No, it is not a leaf node \n";
                }

                sibling = binaryTree.getSibling(root,num);
                if(sibling!=-1){
                     cout <<"The sibling of "<<num<<" is "<<sibling<<endl;
                }

                leftChild=binaryTree.getLeftChild(root,num);
                if(leftChild!=-1){
                    cout << leftChild <<" is the left child of "<<num<<endl;
                }

                rightChild=binaryTree.getRightChild(root,num);
                if(rightChild!=-1){
                    cout << rightChild <<" is the right child of "<<num<<endl;
                }

            break;			 
            
            case 3:
            cout<<"Total internal nodes = "<<binaryTree.internalNodes(root);
            break;

            case 4:
             cout<<"Total external nodes = "<<binaryTree.externalNodes(root);
            break;	

            case 5:
             cout<<"Total internal links = "<<binaryTree.internalNodes(root)-1;
            break;	

            case 6:
             cout<<"Total external nodes = "<<binaryTree.externalNodes(root);
            break;			 
            
            default :
            break;
        }
    }

    return 0;
}