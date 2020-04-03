/*Level Order
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

Example : Given binary tree

    3
   / \
  9  20
    /  \
   15   7
   
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Also think about a version of the question where you are asked to do a level order traversal of
the tree when depth of the tree is much greater than number of nodes on a level.

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
 
// vector<vector<int> > Solution::levelOrder(TreeNode* A) {
 
//     vector<vector<int>> ans;    
//     int index = 0;
    
//     queue < TreeNode * > q;
    
//     q.push(A);
//     q.push(NULL);
    
//     while ( q.size() > 1 ){
    
//         TreeNode *curr = q.front();
//         q.pop();
        
//         if (curr == NULL){
//             index++;
//             q.push(NULL);
//             continue;
//         }
            
//         ans[index].push_back( curr -> val);
        
//         if ( curr -> left != NULL )
//             q.push( curr -> left );
        
//         if ( curr -> right != NULL )
//             q.push( curr -> right );
        
//     }
    
//     return ans;   
// }





vector<vector<int> > Solution::levelOrder(TreeNode* A) {
 

    vector<vector<int>> ans;  
    int index = 0;
    
    queue < TreeNode * > q;
    q.push(A);
    
    
    while ( !q.empty() ){
        
        int count = q.size();
        
        vector<int> temp;
        
        for (int i = 0; i < count; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            
            temp.push_back( curr -> val);
            
            if ( curr -> left != NULL )
                q.push( curr -> left );
            
            if ( curr -> right != NULL )
                q.push( curr -> right );
        }
        
        ans.push_back(temp);
    }
    
    return ans;   
}
