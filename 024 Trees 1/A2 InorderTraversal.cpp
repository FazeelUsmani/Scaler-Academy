/*
Inorder Traversal:

Given a binary tree, return the inorder traversal of its nodes' values. 

Example : Given binary tree

   1
    \
     2
    /
   3
   
return [1,3,2]. 
Using recursion is not allowed.
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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    stack <TreeNode *> s;
    TreeNode *x = A;
    vector <int> ans;
    
    
    while (!s.empty() || x != NULL){
        
        while (x != NULL){
            s.push(x);
            x = x->left;
        }
        
        x = s.top();
        s.pop();
            
        ans.push_back( x -> val );
        
        x = x->right;
    }
    
    return ans;
}


// Aliter:
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    stack<TreeNode *> s;
    TreeNode *curr = A;
    vector<int> ans;
    
    while (!s.empty() || curr != NULL){
        
        if (curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode *temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            curr = temp->right;
        }
    }
    
    return ans;
}

