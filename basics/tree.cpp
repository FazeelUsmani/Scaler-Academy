#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x){
        data = x;
        left = right = NULL;
    }
};

int main(){

    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);

    a->right->left = new Node(60);
    a->right->right = new Node(70);
    
    return 0;
}


/*
This code creates the following tree
    
          10
      20      30 
   40   50  60   70

*/
