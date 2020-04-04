/*
Difference between odd and even levels

Given a binary tree of integers. Find the difference between the sum of nodes at odd level and sum of nodes at even level. 

Note: Consider the level of root node as 1.

Constraints
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
    10
    Sum of nodes at odd level = 23
    Sum of ndoes at even level = 13

Input 2:
            1
           /  \
          2    10
           \
            4
Output 2:
    -7
    Sum of nodes at odd level = 5
    Sum of ndoes at even level = 12
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
 
int level = 1;
int Solution::solve(TreeNode* A) {
    
    queue < TreeNode *> q;
    q.push ( A );
    int level = 1;
    int oddSum = 0, evenSum = 0;
    
    while ( !q.empty() ){
        
        int count = q.size();
        
        for (int i = 0; i < count; i++){
            
            TreeNode *curr = q.front();
            q.pop();
            
            if (level&1)
                oddSum += curr -> val;
            else
                evenSum += curr -> val;
                
            if ( curr -> left != NULL )
                q.push( curr -> left );
                
            if ( curr -> right != NULL )
                q.push( curr -> right );
            
        }
        level++;
    }
    
    return oddSum - evenSum;    
}
