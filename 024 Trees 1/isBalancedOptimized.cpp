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


int isBalanced(Node *root){

    if (root == NULL)       
        return true;

    int lh = isBalanced ( root -> left );
    if (lh == -1)
        return -1;

    int rh = isBalanced ( root -> right );
    if (rh == -1)
        return -1;
        
    if (abs (lh-rh) > 1) return -1;
    else 
        return max(lh, rh) + 1;
 
}

// TC: O(N)
// SC: O(h)

int main(){

    /*
        Tree is 
            20
            8    12  
        3   5

        Here 3 + 5 = 8
        8 + 12 = 20
        Output is Yes
    */

    // Node *a = new Node(20);

    // a->left = new Node(8);
    // a->right = new Node(12);

    // a->left->left = new Node(3);
    // a->left->right = new Node(5); 

    // int ans = isBalanced(a);

    // cout<< ans;

    // if (ans == -1)
    //     cout<<"NO\n";  
    // else
    //     cout<<"YES\n";

    /* 
    Second Tree is 
                   10
             20         30           
          40     50
        60  70
      80

    */


    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);
    a->left->left->left = new Node(60);
    a->left->left->right = new Node(70); 
    a->left->left->left->left = new Node(80);

    int ans = isBalanced(a);
    cout<<ans;

    if (ans == -1)
        cout<<"NO\n";  
    else
        cout<<"YES\n";
        

    return 0;
}    

 



