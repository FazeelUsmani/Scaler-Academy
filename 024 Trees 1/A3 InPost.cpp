/*
Binary Tree From Inorder And Postorder

Given inorder and postorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree. 
Example :
Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
TreeNode* InPost(vector<int> &inOrder, vector<int> &postOrder, int is, int ie, int ps, int pe){
    
    if (ie < is)
        return NULL;
    
    TreeNode *root = new TreeNode(postOrder[pe]);
    int index = Imap[root -> val];
    
    root -> left = InPost(inOrder, postOrder, is, index-1, ps, ps+(index - is)-1);
    root -> right = InPost(postOrder, postOrder, index+1, ie, ps+(index-is), pe-1);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    // if (A.size() == 1){
    //     TreeNode *x = new TreeNode(A[0]);
    //     return x;
    // }
    
    for (int i = 0; i < A.size(); i++)
        Imap[ A[i] ] = i;
    
    return InPost(A, B, 0, A.size()-1, 0, B.size()-1);
}
