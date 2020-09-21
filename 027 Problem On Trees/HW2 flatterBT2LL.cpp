/*

Flatten Binary Tree to Linked List
Problem Description

Given a binary tree A, flatten it to a linked list in-place.

The left child of all nodes should be NULL.



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the head of tree A.



Output Format
Return the linked-list after flattening.



Example Input
Input 1:

     1
    / \
   2   3
Input 2:

         1
        / \
       2   5
      / \   \
     3   4   6


Example Output
Output 1:

1
 \
  2
   \
    3
Output 2:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


Example Explanation
Explanation 1:

 Tree flattening looks like this.
Explanation 2:

 Tree flattening looks like this.

*/

/*
    THIS SOLUTION WILL GIVE YOU MEMORY LIMIT EXCEEDED ERROR --> O(N) SPACE. 
    THINK OF RECURSION TO HAVE O(H) SPACE. 
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

vector<int> preOrderTraversal (TreeNode* root)  {
    vector<int> arr;
    stack<TreeNode *> s;
    s.push(root);
    
    while (!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();
        if (curr->right != NULL)
            s.push(curr->right);
        if (curr->left != NULL)
            s.push(curr->left);
        arr.push_back(curr->val);
    }
    
    return arr;
}

TreeNode* Solution::flatten(TreeNode* A) {
    
    vector<int> preOrder = preOrderTraversal(A);
    
    TreeNode* dummy = new TreeNode(0);
    TreeNode* curr = dummy;
    
    for (int x: preOrder) {
        curr->right = new TreeNode(x);
        curr = curr->right;
    }
    
    return dummy->right;
}
