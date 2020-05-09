/*

Equal Tree Partition

Given a binary tree with N nodes. Check whether it is possible to partition the tree to two trees which have equal 
sum of values after removing exactly one edge on the original tree. Return 1 if the tree can be partitioned into two 
trees of equal sum else return 0. 

Constraints
2 <= N <= 100000
-10^9 <= Node values <= 10^9

For Example
Input 1:
                5
               /  \
              3    7
             / \  / \
            4  6  5  6
Output 1:
    1
    Explanation 1:
        Remove edge between 5(root node) and 7: 
        Tree 1 =                                               Tree 2 =
                        5                                                     7
                       /                                                     / \
                      3                                                     5   6    
                     / \
                    4   6
        Sum of Tree 1 = Sum of Tree 2 = 18

Input 2:
                1
               / \
              2   10
                  / \
                 20  2
Output 2:
     0
     Explanation 2:
        The given Tree cannot be partitioned.

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
 
int sumTree(TreeNode *root){
    
    if (root == NULL)
        return 0;
    
    return root->val + sumTree(root->left) + sumTree(root->right);
}
 
bool flag = false;

int checkSum(TreeNode *root, int toAchieve, TreeNode *initialRoot){
    
    if (root == NULL)
        return 0;
        
    int sumLeft = checkSum(root->left, toAchieve, initialRoot);
    int sumRight = checkSum(root->right, toAchieve, initialRoot);
    
    int currSum = sumLeft + sumRight + root->val;
    
    if ((currSum == toAchieve) && (root != initialRoot)){
        flag = true;
        return currSum;
    }
    
    return currSum;
}
 
int Solution::solve(TreeNode* A) {
    
    if (flag)
        flag = !flag;
    
    int sum = sumTree(A);
    if (sum != 0)
        sum = sum/2;
    
    checkSum(A, sum, A);
    
    if (flag)
        return 1;
    return 0;
}
