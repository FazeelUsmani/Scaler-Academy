/*
Given preorder and inorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree. 
Example :
Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3
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
unordered_map <int, int> Imap;
TreeNode* InPreTree(vector<int> &inorder, vector<int> &preorder, int is, int ie, int ps, int pe){
    if (ie < is)
        return NULL;
    
    TreeNode *root = new TreeNode(preorder[ps]);
    int index = Imap[root -> val];
    
    root -> left = InPreTree(inorder, preorder, is, index - 1, ps + 1, ps+(index-is));
    root -> right = InPreTree(inorder, preorder, index+1, ie, ps + (index - is) + 1, pe);
    
    return root;
} 

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    
    for (int i = 0; i < B.size(); i++)
        Imap[ B[i] ] = i;
    
    return InPreTree(B, A, 0, B.size()-1, 0, A.size()-1);
    
}
