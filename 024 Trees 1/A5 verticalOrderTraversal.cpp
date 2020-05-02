/*
Vertical Order traversal of Binary Tree

Given a binary tree, return a 2-D array with vertical order traversal of it.
Go through the example and image for more details. 

Example : Given binary tree:
      6
    /   \
   3     7
  / \     \
 2   5     9
returns
[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]
 Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.
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
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    if (A == NULL)
        return {};
    
    queue <pair<TreeNode *, int>> q;
    q.push(make_pair(A, 0));
    unordered_map <int, vector<int>> umap;
    int _min = INT_MAX;
    int _max = INT_MIN;
    
    while (!q.empty()){
        
        pair<TreeNode *, int> temp = q.front();
        q.pop();
        TreeNode *curr = temp.first;
        int idx = temp.second;
        _min = min(_min, idx);
        _max = max(_max, idx);
        
        umap[idx].push_back(curr->val);
        
        if (curr->left != NULL)
            q.push(make_pair(curr->left, idx-1));
            
        if (curr->right != NULL)
            q.push(make_pair(curr->right, idx+1));
    }
    
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> :: iterator it;
    for (auto it = _min; it <= _max; it++){
        vector<int> temp;
        for (int j = 0; j < umap[it].size(); j++){
            temp.push_back(umap[it][j]);
        }
        ans.push_back(temp);
    }
    return ans;
}
