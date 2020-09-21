/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    TreeNode* root = A;
    
    while (root) {
        TreeNode* curr = root;
        TreeNode* temp = root->right;
        
        curr->right = curr->left;
        curr->left = NULL;
        while (curr->right) {
            curr = curr->right;
        }
        curr->right = temp;
        root = root->right;
    }
    
    return A;
}
