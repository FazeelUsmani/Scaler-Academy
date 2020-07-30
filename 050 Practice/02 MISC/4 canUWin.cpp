/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int maxSize;

int sizeOfTree(TreeNode *root){
    if (root == NULL)
        return 0;
    
    return sizeOfTree(root->left) + sizeOfTree(root->right) + 1;
}

void found(TreeNode *root, int B){
    
    int leftSubTreeSize = sizeOfTree(root->left);
    int rightSubTreeSize = sizeOfTree(root->right);
    maxSize = max(leftSubTreeSize, rightSubTreeSize);
    
    int tot = B - (leftSubTreeSize + rightSubTreeSize + 1);
    maxSize = max(maxSize, tot);
}

void Traverse(TreeNode *root, int C, int B){
    if (root == NULL)
        return;
    
    if (root->left != NULL){
        if (root->left->val == C){
            found(root->left, B);
            return;
        }
        else
            Traverse(root->left, C, B);
    }
    
    if (root->right != NULL){
        if (root->right->val == C){
            found(root->right, B);
            return;
        }
        else
            Traverse(root->right, C, B);
    }
}


int Solution::solve(TreeNode* A, int B, int C) {
    
    maxSize = INT_MIN;
    
    Traverse(A, C, B);
    
    if (maxSize > B/2)
        return 1;
    return 0;
}
