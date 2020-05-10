/*

Sum binary tree or not

Given a binary tree. Check whether the given tree is a Sum-binary tree or not. 
SumTree is a Binary Tree where the value of a node is equal to sum of the nodes 
present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree 
can be considered as 0. A leaf node is also considered as SumTree. 
Return 1 if it sum-binary tree else return 0. 

Input Format
The only argument given is the root pointer of tree A.

Output Format
Return 1 if it is sum-binary tree else return 0.

Constraints
1 <= length of the array <= 100000
0 <= node values <= 50

For Example
Input 1:
       26
     /    \
    10     3
   /  \     \
  4   6      3
Output 1:
    1

Input 2:
       26
     /    \
    10     3
   /  \     \
  4   6      4
Output 2:
    0

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
 
int sumTree(TreeNode* A){
    if (A == NULL)
        return 0;
    int leftSum = sumTree(A->left);
    int rightSum = sumTree(A->right);
    
    
    return leftSum + rightSum + A->val;
}
 
 
int Solution::solve(TreeNode* A) {
    
    if (A == NULL)
        return 0;
    int sum = sumTree(A->left) + sumTree(A->right);
    if (A->val == sum)
        return 1;
    return 0;
}
