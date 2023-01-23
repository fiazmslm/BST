// Checkout this assigment solution on 
// my github whose link in avalilabe bellow
// https://github.com/fiazmslm/ds
// JazakAllah!

#include <iostream>
using namespace std;

class Stack {
   int data;
   Stack *next;
   Stack *top;
public: 
    Stack(){
        data=0;
        next=NULL;
    }

    void push(int val) {
        struct Stack* newStack = (struct Stack*) malloc(sizeof(struct Stack));
        newStack->data = val;
        newStack->next = top;
        top = newStack;
    }

    void pop() {
        if(top==NULL)
        cout<<"Stack Underflow"<<endl;
        else {
            cout<<"The popped element is "<< top->data <<endl;
            top = top->next;
        }
    }

    void display() {
        struct Stack* ptr;
        if(top==NULL)
            cout<<"stack is empty";
        else {
            ptr = top;
            while (ptr != NULL) {
                cout<< ptr->data <<endl;
                ptr = ptr->next;
            }
        }
        cout<<endl;
        top = NULL;
    }

};

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

    // In order traverse.
    void Inorder(BST*,Stack* );

    // Pre order traverse.
    void Preorder(BST*,Stack* );

    // Pre order traverse.
    void Postorder(BST*,Stack* );
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

void BST::Inorder(BST* root,Stack* s ){
    if (root != NULL) {
        Inorder(root->left,s);
        s->push(root->data);
        Inorder(root->right,s);
    }
}

void BST::Preorder(BST* root,Stack* s ){
    if (root != NULL) {
        s->push(root->data);
        Preorder(root->left,s);
        Preorder(root->right,s);
    }
}

void BST::Postorder(BST* root,Stack* s ){
    if (root != NULL) {
        Postorder(root->left,s);
        Postorder(root->right,s);
        s->push(root->data);
    }
}

int main(){
    int data[] = {11,6,15,4,8,13,19,16};
    cout<<"Data\n----------------------\n";
    int dataLength = sizeof(data)/ sizeof(int);
    for(int i=0;i<dataLength;i++){
        cout<<data[i]<<" ";
    }

    BST binaryTree, *root = NULL;
    cout << "BST is being created... \n";

    root = binaryTree.Insert(root, data[0]);
    for(int i=1;i<dataLength;i++){
        binaryTree.Insert(root, data[i]);
    }
    cout << "Done. \n";

    Stack s;

    binaryTree.Inorder(root,&s);
    cout<<"Reverse order of inorder traversal: "<<endl;
    s.display();

    binaryTree.Preorder(root,&s);
    cout<<"Reverse order of preorder traversal: "<<endl;
    s.display();

    binaryTree.Postorder(root,&s);
    cout<<"Reverse order of postorder traversal: "<<endl;
    s.display();

    return 0;
}