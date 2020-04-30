/*
Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [3,2,1]. Using recursion is not allowed.


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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    stack <TreeNode *> s;
    s.push(A);
    vector<int> arr;
    
    while (!s.empty()){
        
        TreeNode *curr = s.top();
        s.pop();
        
        arr.push_back(curr -> val);
        
        if ( curr -> left )
            s.push(curr -> left);
            
        if ( curr -> right )
            s.push(curr -> right);
        
    }
    reverse (arr.begin(), arr.end());
   
    return arr;
}

// Aliter:
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    stack <TreeNode *> s;
    TreeNode *curr = A;
    vector<int> arr;
    
    while (!s.empty() || curr != NULL){
        
        if (curr != NULL){
            arr.push_back(curr->val);
            s.push(curr);
            curr = curr->right;
        }
        else{
            TreeNode *temp = s.top();
            s.pop();
            curr = temp->left;
        }
    }
    reverse (arr.begin(), arr.end());
    
    return arr;
}
