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

int getSize(Node *root){

    if (!root)
        return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int main(){

    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);

    a->right->left = new Node(60);
    a->right->right = new Node(70);
    
    cout<<" \nSize is "<<getSize(a);

       

    return 0;
}    

 
