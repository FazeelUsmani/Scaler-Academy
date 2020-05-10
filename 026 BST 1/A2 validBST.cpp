/*
Valid Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST). 

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example :
Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 
Return 0 / 1 ( 0 for false, 1 for true ) 
for this problem SOLUTION APPROACH : VIDEO : https://www.youtube.com/watch?v=yEwSGhSsT0U Complete solution in the hints.

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

 
bool isBST(TreeNode* root, int _min, int _max){
    if (root == NULL)
        return true;
        
    return ((root->val > _min) && (root->val < _max) && (isBST(root->left, _min, root->val)) && (isBST(root->right, root->val, _max)) );
} 
 
int Solution::isValidBST(TreeNode* A) {
    if (isBST(A, INT_MIN, INT_MAX))
        return 1;
    return 0;
}

