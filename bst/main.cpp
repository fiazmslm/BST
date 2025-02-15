// Checkout this assigment solution on 
// my github whose link in avalilabe bellow
// https://github.com/fiazmslm/ds
// JazakAllah!

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

    // parent of a node.
    int getParent(BST*,int);

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
        }else if(root->data > key)
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

bool isPrime(int n)
{
	int i;
	bool prime=true;
	
	for(i=2;i<(n/2);i++)
	{
		if(n%i==0)
		{
			prime=false;
			break;
		}
	}
	return prime;
}

bool isEven(int n)
{
    if( n%2 == 0)
        return true;

    return false;
}

int BST::getParent(BST* root, int value)
{
   if(root->left == NULL && root->right == NULL)
    return -1;

   if(root->left && root->left->data == value)
    return root->data;

   if(root->right && root->right->data == value)
    return root->data;

   if(root->left && root->data > value)
    return getParent(root->left,value);

   if(root->right && root->data < value)
    return getParent(root->right,value);

    return -1;
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
    int data[] = {11,6,15,4,8,13,19,16};
    cout<<"Data\n----------------------\n";
    int dataLength = sizeof(data)/ sizeof(int);
    for(int i=0;i<dataLength;i++){
        cout<<data[i]<<" ";
    }

    BST binaryTree, *root = NULL;
    int n=1,sibling,parent,leftChild,rightChild;
    while (n<6 && n>0) {
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
                }else{
                    cout <<"There is no sibling of "<<num<<endl;
                }

                parent = binaryTree.getParent(root,num);
                if(parent!=-1){
                     cout <<parent<<" is the parent of "<<num<<endl;
                }else{
                    cout <<"There is no parent of "<<num<<" as its a root node"<<endl;
                }

                leftChild=binaryTree.getLeftChild(root,num);
                if(leftChild!=-1){
                    cout << leftChild <<" is the left child of "<<num<<endl;
                }else{
                    cout <<"There is no left child of "<<num<<endl;
                }

                rightChild=binaryTree.getRightChild(root,num);
                if(rightChild!=-1){
                    cout << rightChild <<" is the right child of "<<num<<endl;
                } else{
                    cout <<"There is no right child of "<<num<<endl;
                }

                if(isPrime(num)){
                    cout<<num<<" is a prime number"<<endl;
                }else{
                     cout<<num<<" is not a prime number"<<endl;
                }

                if( isEven(num)){
                    cout<<num<<" is a even number"<<endl;
                }else{
                     cout<<num<<" is a odd number"<<endl;
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