#include<bits/stdc++.h>
using namespace std;

int dp[100];

void dfs(vector<int> &a, vector<int> v[], int u, int parent){
    
    dp[u] = a[u-1];

    int maximum = 0; 
    for (int child : v[u]) { 
  
        if (child == parent) 
            continue; 
  
        dfs(a, v, child, u); 
  
        maximum = max(maximum, dp[child]); 
    } 
  
    dp[u] += maximum; 
}


int solve(vector<int> &A, vector<int> &B) {
    
    cout<<"woehoi";
    vector<int> adj[A.size()];
    
    for (int i = 0; i < A.size(); ++i){
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }
    
    dfs (A, adj, 1, 0);
    
    return dp[1];
}


int main(){   

    vector<int> A{0,1,1,2,2,3}, B{3,1000,5,1,3,10};
    cout<<solve(A, B);
        
    return 0;
}
