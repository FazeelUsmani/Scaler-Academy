#include<bits/stdc++.h>
using namespace std;

vector<int> g[1111111]; 
pair<int, int> ans;    // storing {distance, node};

void dfs(int v, int parent = -1, int distance = 0){

    if (distance > ans.first){
        ans = {distance, v};
    }

    for (int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if (to != parent){
            dfs(to, v, distance+1);
        }
    }
}


int diameterTreeusingGraph(vector<int> &A){

    
    for (int i = 0; i < A.size(); ++i){
        if (A[i] != -1){
            g[A[i]].push_back(i);
            g[i].push_back(A[i]);
        }
    }

    int v = 0;
    ans = {-1, -1};
    dfs(v);
    v = ans.second;
    dfs(v);  

    return ans.first;
}

int main(){

    vector<int> A{-1,0,0,0,2,3,5};
    cout<<diameterTreeusingGraph(A)<<endl;

    return 0;
}