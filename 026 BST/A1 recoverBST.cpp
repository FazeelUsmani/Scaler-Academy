/*

Recover Binary Search Tree
Problem Description

Two elements of a binary search tree (BST),represented by root A are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.

A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the head of the tree,A



Output Format
Return the 2 elements which need to be swapped.



Example Input
Input 1:

 
         1
        / \
       2   3
Input 2:

 
         2
        / \
       3   1



Example Output
Output 1:

 [2, 1]
Output 2:

 [3, 1]


Example Explanation
Explanation 1:

Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST 
Explanation 2:

Swapping 1 and 3 will change the BST to be 
         2
        / \
       1   3
which is a valid BST 



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
void inorder(TreeNode *root,vector <int> &v)
{
    if(!root)
        return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}

vector<int> Solution::recoverTree(TreeNode* root) {
    vector <int> v;
    inorder(root,v);
    int first=0,mid=0,last=0;
    int count=0,i;
    vector <int> result;
    for(i=1;i<v.size();i++)
    {
        if(v[i]<v[i-1] && count==0)
        {
            first = i-1;
            mid = i;
            count = 1;
        }
        else if(v[i]<v[i-1] && count==1) 
        {
            last = i;
            count = 2;
        }
    }
    if(last!=0)
    {
        result.push_back(v[last]);
        result.push_back(v[first]);
    }
    else
    {
        result.push_back(v[mid]);
        result.push_back(v[first]);
    }
    return result;
}

