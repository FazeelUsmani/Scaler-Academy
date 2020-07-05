/*

Make Circle

Problem Description

Given an array of strings A of size N, find if the given strings can be chained to 
form a circle.

A string X can be put before another string Y in circle if the last character of X 
is same as first character of Y.

NOTE: All strings consist of lower case characters.



Problem Constraints
1 <= N <= 105

Sum of length of all strings <= 106



Input Format
First and only argument is a string array A of size N.



Output Format
Return an integer 1 if it is possible to chain the strings to form a circle
else return 0.



Example Input
Input 1:

 A = ["aab", "bac", "aaa", "cda"]
Input 2:

 A = ["abc", "cbc"]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 We can chain the strings aab -> bac -> cda -> aaa -> aab. So this forms a circle. So, output will be 1. 
Explanation 2:

 There is no way to chain the given strings such that they forms a circle.

*/

#include<bits/stdc++.h>
using namespace std;

/*

LOGIC: To make a circle, it should satisfy the following conditions:-
1) Indegree and Outdegree of each node should be same
2) The graph should be strongly connected i.e. no node is left unconnected.
**This can be done using DFS and marking the visited nodes and 
**later checking with the original mark array

*/

void dfs(vector<int> g[], int u, bool vis[]){
    vis[u] = true;
    for (int i = 0; i < g[u].size(); ++i)
        if (!vis[g[u][i]])
            dfs(g, g[u][i], vis);
}

bool isConnected(vector<int> g[], bool mark[], int x){

    bool vis[26] = {false};

    dfs(g, x, vis);

    for (int i = 0; i < 26; ++i){
        if (mark[i] != vis[i]){
            return false;
        }
    }

    return true;
}

int makeCircle(vector<string> & A){

    vector<int> g[26];
    bool mark[26] = {false};
    int in[26] = {0}, out[26] = {0};

    for (int i = 0; i < A.size(); ++i){
        int f = A[i].front() - 'a';
        int l = A[i].back() - 'a';

        mark[f] = mark[l] = true;

        out[f]++;
        in[l]++;
           
        g[f].push_back(l);
    }

    for (int i = 0; i < 26; ++i){
        if (in[i] != out[i]){
            return false;
        }
    }

    return isConnected(g, mark, A[0].front()-'a');
}

int main(){
    vector<string> A{"aab", "cda"};
    cout<<makeCircle(A);

    return 0;
}