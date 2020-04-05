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

int height (Node *root){

    if (root == NULL)
        return -1;
    
    return 1 + max( height(root->left), height(root -> right) );
}


bool isBalanced(Node *root){

    if (root == NULL)       
        return true;

    int lh = height ( root -> left);
    int rh = height ( root -> right );

    return ( (abs (lh-rh) <= 1) && isBalanced(root->left) && isBalanced(root->right) );
 
}
// ^ ^ ^ ^
// | | | |
// TC: O(N^2)  
// SC: O(h)


// Now, I'm going to discuss the O(N) solution

int isBalanced2(Node *root){
    if (root == NULL)
        return 0;
    
    int lh = isBalanced2( root -> left );
    if ( lh == -1 )     return -1;

    int rh = isBalanced2 ( root -> right );
    if ( rh == -1 )     return -1;

    if ( abs( lh - rh ) > 1 )     return -1;
    else    return max(lh,rh) + 1;   
}



// class Solution {

//     bool isBalanced(TreeNode *root) {
//         if (root == NULL) return true;
//         return isBalancedWithDepth(root).second;
//     }

//     pair<int, bool> isBalancedWithDepth(TreeNode *root) {
//         if (root == NULL) return make_pair(0, true);

//         pair<int, bool> left = isBalancedWithDepth(root->left);

//         pair<int, bool> right = isBalancedWithDepth(root->right);
        
//         int depth = max(right.first, left.first) + 1;
        
//         bool isbalanced = right.second && left.second && (abs(right.first - left.first) < 2);
        
//         return make_pair(depth, isbalanced);
//     }
// };


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

    // bool ans = isBalanced(a);

    // if (ans)
    //     cout<<"YES\n";
    // else
    //     cout<<"NO\n";  

    /* 
    Tree is 
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

    bool ans = isBalanced(a);

    if (ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";  

    cout<<isBalanced2(a);

    return 0;
}    

 



