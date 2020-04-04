/*
ZigZag Level Order Traversal BT

Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

Example : Given binary tree

3
   / \
  9  20
    /  \
   15   7

return
[
         [3],
         [20, 9],
         [15, 7]
]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int>> ans; 
    queue < TreeNode * > q1, q2;
    q1.push( A );
    int toggle = 1;
    
    while ( !q1.empty() || !q2.empty() ){
        
        vector<int> temp;
            
        if ( toggle ){
            int n = q1.size();
            while ( n-- ){
                TreeNode *curr = q1.front();
                q1.pop();
                
                temp.push_back( curr -> val);
                if ( curr -> right != NULL)
                    q2.push( curr -> right );
                
                if ( curr -> left != NULL )
                    q2.push( curr -> left );
            } 
        }
        
        else{
            int n = q2.size();
            while ( n-- ){
                TreeNode *curr = q2.front();
                q2.pop();
                
                temp.push_back( curr -> val);
                if ( curr -> right != NULL)
                    q1.push( curr -> right );
                
                if ( curr -> left != NULL )
                    q1.push( curr -> left );
            }
        }
        
        if (toggle)
            reverse(temp.begin(), temp.end());
        
        toggle ^= 1;
            
        ans.push_back( temp );
    }
    
    return ans;
}
