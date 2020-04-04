/*Symmetric Binary Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). 

Example :
    1
   / \
  2   2
 / \ / \
3  4 4  3

The above binary tree is symmetric. But the following is not:
    1
   / \
  2   2
   \   \
   3    3

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int isSameTree ( TreeNode *A, TreeNode *B ){
 
    if ( !A && !B )
        return 1;
    
    if ( !A || !B )
        return 0;
        
    return ( (A -> val) == (B -> val) ) &&
           ( isSameTree ( A -> left, B -> right) ) && 
           ( isSameTree ( A -> right, B -> left) );
        
}
 
int Solution::isSymmetric(TreeNode* A) {
    
    if ( !A )
        return 1;
    
    if ( A ){
        if ( isSameTree( A -> left, A -> right ) ) 
            return 1;
    }
    return 0;
}
