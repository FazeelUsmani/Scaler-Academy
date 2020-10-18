/*

Max Sum Path in Binary Tree
Problem Description

Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.



Problem Constraints
1 <= Number of Nodes <= 7e4

-1000 <= Value of Node in T <= 1000



Input Format
The first and the only argument contains a pointer to the root of T, A.



Output Format
Return an integer representing the maximum sum path.



Example Input
Input 1:

  
    1
   / \
  2   3
Input 2:

       20
      /  \
   -10   20
        /  \
      -10  -50


Example Output
Output 1:

 6
Output 2:

 40


Example Explanation
Explanation 1:

     The path with maximum sum is: 2 -> 1 -> 3
Explanation 2:

     The path with maximum sum is: 20 -> 20


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
int recurse(TreeNode *root, int &result) {
    if(root == nullptr) {
        return 0;
    }

    int left = recurse(root->left, result);
    int right = recurse(root->right, result);

    int max_single = max(max(left, right) + root->val, root->val);
    int max_top = max(max_single, left + right + root->val);

    result = max(max_top, result);

    return max_single;
}

int Solution::maxPathSum(TreeNode* A) {
    int result = INT_MIN;
    recurse(A, result);

    return result;
}
