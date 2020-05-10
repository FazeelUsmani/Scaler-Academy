/*
Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding 
up all the values along the path equals the given sum.

Example : Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
        
        
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22. Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
bool flag = false;
int checkPath (TreeNode* root, int B, int sum, int depth){
     
    if (root == NULL)
        return 0;
    
    if (sum + root->val == B && root->left == NULL && root->right == NULL){
        flag = true;
        return 0;
    }
    
    int l = checkPath (root->left, B, sum+root->val, depth+1);
    int r = checkPath (root->right, B, sum+root->val, depth+1);
        
    return sum;
} 

int Solution::hasPathSum(TreeNode* A, int B) {
    if (flag)
        flag = !flag;
    
    checkPath(A, B, 0, 0);    
    
    if (flag)
        return 1;
    return 0;
}
