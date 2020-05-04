/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int height(TreeNode* A){
    if (A == NULL)
        return -1;
        
    int lh = height(A->left);
    int rh = height(A->right);
        
    return max(lh, rh) + 1;
}


int Solution::isBalanced(TreeNode* A) {
    
    if (A == NULL)
        return 1;
        
    int lh = height(A->left);
    int rh = height(A->right);
    
    if (lh == -1 && rh == -1)
        return 1;
            
    return !(abs(lh-rh)>1) && isBalanced(A->left) && isBalanced(A->right);
    
}
