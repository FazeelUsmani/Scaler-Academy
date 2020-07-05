#include<bits/stdc++.h>
using namespace std;

int solve(int A, vector<vector<int> > &B, int C, int D){

    if (C == D)
        return 0;

    vector<vector<pair<int, int> > > adj(A);

    for (vector<int> x : B){
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }        

    vector<queue<int> > q (2*A);
    bool visited[A] = {false};
    q[0].push(C);

    for (int i = 0; i < 2*A; ++i){

        while (!q[i].empty()){
            int front = q[i].front();
            q[i].pop();
            if (front == D)
                return i;

            if (!visited[front]){
                visited[front] = true;
                for (pair<int, int> p : adj[front]){
                    if (!visited[p.first]){
                        q[i + p.second].push(p.first);
                        visited[p.first];
                    }                
                }  
            }                          
        }
    }

    return -1;
}

int main(){

    vector<vector<int> > B { {3,11,2}, {5,12,1}, {0,7,2}, {5,6,2}, {6,10,1}, {5,9,1} };
    int A = 13, C = 9, D = 4;

    cout<<solve(A, B, C, D);    

    return 0;
}