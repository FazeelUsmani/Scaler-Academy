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


void printDLL(Node *head){

    Node *curr;

    while ( head -> right != NULL ){
        cout<< head -> data <<" ";
        curr = head;
    }
    cout<<"\nFrom Ending ";
    while ( curr -> left != NULL ){
        cout<<curr -> data <<" ";
    }
}

Node *prev1 = NULL;
Node BT2DLL(Node *root){
    if ( root = NULL )  return root;

    Node *head = BT2DLL( root -> left );

    if ( prev1 == NULL)
        head = root;

    else{
        prev1 -> right = root;
        root -> left = prev1;
    }

    prev1 = root;

    BT2DLL ( root -> right );

    return head;
}

// TC: O(N)
// SC: O(h)

int main(){

    /*
        Input: Tree 

             10
          5     20  
              30  35 

        Output: Inorder Traversal of Binary Tree
        DLL: 5 <-> 10 <-> 30 <-> 20 <-> 35 
    */

    Node *a = new Node(20);

    a->left = new Node(8);
    a->right = new Node(12);

    a->left->left = new Node(3);
    a->left->right = new Node(5); 


    Node *ans = BT2DLL(a);
    printDLL(ans);

  

    return 0;
}    

 



