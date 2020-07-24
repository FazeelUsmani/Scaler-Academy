#include<bits/stdc++.h>
using namespace std;

vector<int> g[6];

void addEdge(int u, int v){
    g[u].push_back(v);
}

void topologicalSort(){
    int in[6] = {0};
    
    for (int i = 0; i < 6; ++i){
        for (int x : g[i]){
            in[x]++;
        }        
    }

    for (int i = 0; i < 6; ++i)
        cout<<in[i]<<", ";
    cout<<endl;
    int vis[6] = {0};

    queue<int> q;
    for (int i = 0; i < 6; ++i){
        if (in[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<" --> ";
        for (int x : g[front]){
            in[x]--;
            if (in[x] == 0 && !vis[x]){
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    
}

int main(){

    addEdge(4, 1);
    addEdge(4, 0);
    addEdge(5, 0);
    addEdge(5, 2);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort();

    for (int i = 0; i < 6; ++i){
        cout<<i<<" --> ";
        for (int x : g[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}

