#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int A, vector<vector<int> > &B) {
    
    vector<int> adj[A+1];
    
    for (auto i : B){
        adj[i[0]].push_back(i[1]);
    }
    
    int in[A+1] = {0};
    for (int i = 1; i <= A; ++i){
        for (int x : adj[i]){
            in[x]++;
        }
    }
    
    priority_queue <int, vector<int>, greater<int> > pq;
    int vis[A+1] = {0};
    for (int i = 1; i <= A; ++i){
        if (in[i] == 0){
            pq.push(i);
            vis[i] = 1;
        }
    }
    
    vector<int> ans;
    while (!pq.empty()){
        
        int temp = pq.top();
        pq.pop();
        ans.push_back(temp);
        
        sort(adj[temp].begin(), adj[temp].end());
        
        for (int x : adj[temp]){
            in[x]--;
            if (!vis[x] && in[x] == 0){
                pq.push(x);
                vis[x] = 1;
            }
        }
    }
    
    return ans;
}

int main(){
    int A = 6;
    vector<vector<int> > B { {6, 3}, {6, 1}, {5, 1}, {5, 2}, {3, 4}, {4, 2} };
    
    for (int x : solve(A,B))
        cout<<x<<" ";

    return 0;
}