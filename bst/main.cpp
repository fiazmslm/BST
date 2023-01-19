#include <iostream>
using namespace std;

class BST{
    int data;
    BST *left,*right;
public:
    // Parameterized constructor.
    BST(int);


};

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

int main(){
    cout<<"Hello World";
}