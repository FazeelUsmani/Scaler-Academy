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

int getMax(Node *root){
    if (root == NULL)
        return INT_MIN;
    else
        return max(root->data, max(getMax(root->left), getMax(root->right)));
    
}


int main(){

    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);

    a->right->left = new Node(60);
    a->right->right = new Node(70);
    
    cout<<" \nMax is "<<getMax(a);

    return 0;
}
