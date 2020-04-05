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


void inOrder(Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            curr = curr->left; 
        } 
          
        curr = s.top(); 
        s.pop(); 
        cout << curr->data << " "; 
        curr = curr->right; 
    } 
    cout<<endl;
} 


void inOrderRecursive (Node *root){
    if (root == NULL)
        return;

    inOrderRecursive(root->left);
    cout<<root->data<<" ";
    inOrderRecursive(root->right);    
}


int main(){

    // Node *a = new Node(10);
    
    // a->left = new Node(20);
    // a->right = new Node(30);

    // a->left->left = new Node(40);
    // a->left->right = new Node(50);

    // a->right->left = new Node(60);
    // a->right->right = new Node(70);


    Node *a = new Node(10);
    a -> left = new Node(20);
    a -> left -> right = new Node (80);

    Node *b = new Node (30);
    a -> right = b;
    b -> left = new Node (40);
    b -> right = new Node (60);
    b -> left -> left = new Node (50);
    b -> left -> left -> right = new Node (70);
    
    inOrder(a);                   // Using stack
    inOrderRecursive(a);          // Using Recursion

    return 0;
}

