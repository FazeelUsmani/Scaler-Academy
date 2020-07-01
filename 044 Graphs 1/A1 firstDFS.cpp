/*

First Depth First Search
Problem Description

You are given n towns (1 to n). All towns are connected via unique directed path as mentioned in the input.

Given 2 towns find whether you can reach the first town from the second without repeating any edge.

x y : query to find whether x is reachable from y.

Input contains an integer array A of size n and 2 integers x and y ( 1 <= x, y <= n ).

There exist a directed edge from A[i] to i+1 for every 1 <= i < n. Also, it's guaranteed that A[i] <= i.

NOTE: Array A is 0-indexed.



Problem Constraints
1 <= n <= 100000



Input Format
First argument is vector A

Second argument is integer B

Third argument is integer C



Output Format
Return 1 if reachable, 0 otherwise.



Example Input
Input 1:

 A = [1, 1, 2]
 B = 1
 C = 2
Input 2:

 A = [1, 1, 2]
 B = 2
 C = 1


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 Tree is 1--> 2--> 3 and hence 1 is not reachable from 2.
Explanation 2:

 Tree is 1--> 2--> 3 and hence 2 is reachable from 1.

*/

int isPath(vector<int> &A, const int B, const int C, vector<vector<int> > &adj){

    // BFS
    if (B == C)
        return true;
    queue <int> q;
    vector<int> visited (A.size() + 1, 0);
        
    q.push(B);
    visited[B] = 1;
    
    while (!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; ++i){
            int front = q.front();
            q.pop();
            if (front == C)
                return true;
            for (int x : adj[front]){
                if (!visited[x]){
                    if (x == C)
                        return true;
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
    }

    return false;    
}

int Solution::solve(vector<int> &A, const int B, const int C) {
    
    int n = A.size();
    vector<vector<int> > adj(n+1);
    
    // Adding Edges
    for (int i = 0; i < n; ++i){
        adj[i+1].push_back(A[i]);
    }
    
    return isPath(A, B, C, adj);   
    // Instead of the whole array can also pass just the size of A :)
}
