/*
TOP VIEW

Given a binary tree of integers. Return an array of integers representing the Top view of the Binary tree.
Top view of a Binary Tree is a set of nodes visible when the tree is visited from Top side. 

Note: Return the nodes in any order. Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9 

For Example
Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 
Output 1:
    [1, 2, 4, 8, 3, 7]

Input 2:
            1
           /  \
          2    3
           \
            4
             \
              5
Output 2:
    [1, 2, 3]
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
vector<int> Solution::solve(TreeNode* A) {
    
    if (A == NULL)
        return {};
        
    queue<pair<TreeNode *, int>> q;
    unordered_map<int, vector<int>> dict;
    q.push(make_pair(A, 0));
    int _min = INT_MAX, _max = INT_MIN;
    
    while (!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++){
            TreeNode *curr = q.front().first;
            int index = q.front().second;
            q.pop();
            _min = min(_min, index);
            _max = max(_max, index);
            dict[index].push_back(curr->val);
            
            if (curr->left)
                q.push(make_pair(curr->left, index-1));
            if (curr->right)
                q.push(make_pair(curr->right, index+1));
        }
    }
    
    vector<int> ans;
    for (int i = _min; i <= _max; i++){
        ans.push_back(dict[i][0]);
    }
    return ans;
}
