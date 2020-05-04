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
    vector<vector<int> > ans;
    queue<TreeNode *> q;
    q.push(A);
    stack<TreeNode *> s;
    int reverse = 0;
    
    while (!q.empty()){
        
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++){
            TreeNode *curr = q.front();
            q.pop();
            if (reverse)
                s.push(curr);
            else
                temp.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        
        if (reverse){
            while (!s.empty()){
                TreeNode *curr = s.top();
                temp.push_back(curr->val);
                s.pop();
            }
        }
        ans.push_back(temp);
        reverse ^= 1;
    }
    
    return ans;
}
