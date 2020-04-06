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

void printKDist(Node *root, int k){

    if ( !root )
        return;
    
    if ( k == 0 )
        cout<<root->data<<" ";

    else{
        printKDist(root->left, k-1);
        printKDist(root->right, k-1);
    }
}

int main(){

    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);

    a->right->left = new Node(60);
    a->right->right = new Node(70);
    
    cout<<" \nNodes at 0 distance are ";
    printKDist(a, 0);       // Root Node

    cout<<" \nNodes at 1 distance are ";
    printKDist(a, 1);       // Level 1

    cout<<" \nNodes at 2 distance are ";
    printKDist(a, 2);       // Level 2

       
    return 0;
}    

 
