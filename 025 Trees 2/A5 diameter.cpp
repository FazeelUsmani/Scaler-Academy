/*

Diameter of binary tree

Problem Description
Given a Binary Tree A consisting of N integer nodes, you need to find the diameter of the tree. 
he diameter of a tree is the number of nodes on the longest path between two leaves in the tree.    


Problem Constraints
0 <= N <= 105


Input Format
First and only Argument represents the root of binary tree A.


Output Format
Return an single integer denoting the diameter of the tree.


Example Input
Input 1:
           1
         /   \
        2     3
       / \
      4   5
Input 2:
            1
          /   \
         2     3
        / \     \
       4   5     6
   


Example Output
Output 1:
 4
Output 2:
 5
   


Example Explanation
Explanation 1:
 Longest Path in the tree is 4 -> 2 -> 1 -> 3 and the number of nodes in this path is 4 so diameter is 4.
Explanation 2:
 Longest Path in the tree is 4 -> 2 -> 1 -> 3 -> 6 and the number of nodes in this path is 5 so diameter is 5.
   
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


int dia = 0;
int diameter(TreeNode* A){
    if (A == NULL)
        return 0;
    int lh = diameter(A->left);
    int rh = diameter(A->right);
    dia = max(dia, lh+rh+1);     // changing diameter
    
    return (max(lh,rh)+1);       // returning height
}

int Solution::solve(TreeNode* A) {
    
    dia = 0;
    int x = diameter(A);
    
    return dia;
}
