/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int>> ans;
    stack<TreeNode *> s1, s2;
    s1.push(A);
    int toggle = 1;
    
    while (!s1.empty() || !s2.empty()){
        
        vector<int> temp;
        
        if (toggle){
            while (!s1.empty()){
                TreeNode *curr = s1.top();
                s1.pop();
                temp.push_back(curr->val);
                
                if (curr->left)
                    s2.push(curr->left);
                if (curr->right)
                    s2.push(curr->right);
            }
        }

        else{
            while(!s2.empty()){
                TreeNode *curr = s2.top();
                s2.pop();
                temp.push_back(curr->val);

                if (curr->right)
                    s1.push(curr->right);
                if (curr->left)
                    s1.push(curr->left);
            }
        }
        toggle ^= 1;
        ans.push_back(temp);
    }
    
    return ans;
}
