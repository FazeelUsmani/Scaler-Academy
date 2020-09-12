/*
Largest BST Subtree
Problem Description

Given a Binary Tree A with N nodes.

Write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).

If the complete Binary Tree is BST, then return the size of whole tree.

NOTE:

Largest subtree means subtree with most number of nodes.


Problem Constraints
1 <= N <= 105



Input Format
First and only argument is an pointer to root of the binary tree A.



Output Format
Return an single integer denoting the size of the largest subtree which is also a BST.



Example Input
Input 1:

     10
    / \
   5  15
  / \   \ 
 1   8   7
Input 2:

     5
    / \
   3   8
  / \ / \
 1  4 7  9


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 Largest BST subtree is
                            5
                           / \
                          1   8
Explanation 2:

 Given binary tree itself is BST.
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

struct Info
{
    int s,min,max;
    bool f;
}; 

Info find(TreeNode *k)
{
    if(k==NULL)
    {
        Info i;
        i.min=0;
        i.max=0;
        i.s=-1;
        i.f=false;
        return i;
    }
    if(k->left==NULL && k->right==NULL)
    {
        Info i;
        i.min=k->val;
        i.max=k->val;
        i.s=1;
        i.f=true;
        return i;
    }
    Info l=find(k->left);
    Info r=find(k->right);
    Info p;
    if(l.s>0 && r.s>0 && l.f && r.f && k->val>l.max && k->val<r.min)
    {
        p.s=l.s+r.s+1;
        p.f=true;
        p.min=l.min;
        p.max=r.max;
    }
    else if(l.s==-1 && r.s>0 && r.f && k->val<r.min)
    {
        p.s=r.s+1;
        p.f=true;
        p.min=k->val;
        p.max=r.max;
    }
    else if(l.s>0 && l.f && r.s==-1 && k->val>l.max)
    {
        p.s=l.s+1;
        p.f=true;
        p.min=l.min;
        p.max=k->val;
    }
    else
    {
        p.f=false;
        p.s=max(l.s,r.s);
        p.min=0;
        p.max=0;
    }
    return p;
} 


int Solution::solve(TreeNode* A) {
    
    Info r=find(A);
    
    return r.s;
}
