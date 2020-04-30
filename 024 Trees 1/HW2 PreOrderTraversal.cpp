/*
reorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,2,3]. Using recursion is not allowed.
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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    stack <TreeNode *> s;
    s.push(A);
    vector<int> arr;
    
    while (!s.empty()){
        TreeNode *x = s.top();
        s.pop();
        if (x->right != NULL)
            s.push(x->right);
            
        if (x->left != NULL)
            s.push(x->left);
            
        arr.push_back(x -> val);
    }
    
    return arr;
}


// Aliter: 

vector<int> Solution::preorderTraversal(TreeNode* A) {

    stack <TreeNode *> s;
    TreeNode *curr = A;
    vector<int> arr;

    while (!s.empty() || curr != NULL){
        if (curr != NULL){
            arr.push_back(curr->val);
            s.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode *temp = s.top();
            s.pop();
            curr = temp->right;
        }
    }
    
    return arr;
}
