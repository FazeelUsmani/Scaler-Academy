#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


void preOrder(Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
    s.push(curr);
  
    while ( s.empty() == false ) 
    { 
        Node *x = s.top();
        s.pop();

        if (x->right != NULL)            
            s.push(x->right);

        if (x->left != NULL)
            s.push(x->left);

        cout<< x->data <<" ";
        
    } 
    cout<<endl;
} 


void preOrderRecursive (Node *root){
    if (root == NULL)
        return;

    cout<<root->data<<" ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);    
}


int main(){

    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);

    a->right->left = new Node(60);
    a->right->right = new Node(70);
    
    preOrder(a);                   // Using stack
    preOrderRecursive(a);          // Using Recursion

    return 0;
}

