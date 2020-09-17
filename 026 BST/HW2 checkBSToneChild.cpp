/*

Check for BST with exactly one child of each internal nodes

Given preorder traversal of a binary tree, check if it is possible that it is also a preorder traversal of a BST,
where each internal node (non -leaf nodes) have exactly one child. 

CONSTRAINTS
1 <= N <= 100

INPUT
    A : [ 4, 10, 5 ,8 ]
    
OUTPUT
    YES
    
EXPLANATION
    The possible BST is:

            4
             \
             10
             /
             5
              \
              8
*/

bool check(vector<int> A, int curr, int low, int high){
    if (curr == A.size())
        return 1;
    
    if (A[curr] < low) return 0;
    if (A[curr] > high) return 0;
    
    bool a = check (A, curr+1, low, A[curr]);
    bool b = check (A, curr+1, A[curr], high);
    
    return a | b;
}

string Solution::solve(vector<int> &A) {
    
    if (check(A, 0, INT_MIN, INT_MAX))
        return "YES";
    else
        return "NO";
        
}
