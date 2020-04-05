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


bool childrenSumProperty(Node *root){

    if ( root == NULL )
        return true;
    
    if ( root -> left == NULL && root -> right == NULL)    
        return true;                  // Don't forget to write this base case
                                      // When it reaches base case then it should return true instead of maybe false
    
    int sum = 0;
    if ( root -> left != NULL )
        sum += root -> left -> data;
    if ( root -> right != NULL )
        sum += root -> right -> data;
    
    return ((root->data == sum) && (childrenSumProperty(root->left)) && (childrenSumProperty(root->right)));
    
}

// TC: O(N)
// SC: O(h)

int main(){

    Node *a = new Node(20);

    a->left = new Node(8);
    a->right = new Node(12);

    a->left->left = new Node(3);
    a->left->right = new Node(5); 

    bool ans = childrenSumProperty(a);

    if (ans)
        cout<<"YES";
    else
        cout<<"NO";
    

    return 0;
}    

 
/*
Tree is 
      20
    8    12  
  3   5

  Here 3 + 5 = 8
  8 + 12 = 20
  Output is Yes
*/
