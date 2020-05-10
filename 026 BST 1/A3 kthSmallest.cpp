/*
Kth Smallest Element In Tree

Given a binary search tree, write a function to find the kth smallest element in the tree. 

Example :
Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 
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

TC: O(H+K)
 
int cnt = 0;
int small = 0;
void printK(TreeNode* root, int k){
    if (root != NULL){
        printK(root->left, k);
        cnt++;
        if (cnt == k){
            small = root->val;
            return;
        }
        printK(root->right, k);
    }
}

int Solution::kthsmallest(TreeNode* A, int B) {
    cnt = 0;
    small = 0;
    printK(A, B);
    
    return small;
}
