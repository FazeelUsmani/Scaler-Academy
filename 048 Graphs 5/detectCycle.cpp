#include<bits/stdc++.h>
using namespace std;
#define n 7

vector<int> g[6];

void addEdge(int u, int v){
    g[u].push_back(v);
}

vector<int> topologicalSort(){
    int in[n] = {0};
    
    for (int i = 0; i < n; ++i){
        for (int x : g[i]){
            in[x]++;
        }        
    }

    for (int i = 0; i < n; ++i)
        cout<<in[i]<<", ";
    cout<<endl;
    int vis[n] = {0};

    queue<int> q;
    for (int i = 0; i < n; ++i){
        if (in[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }

    vector<int> ans;
    while (!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        cout<<front<<" --> ";
        for (int x : g[front]){
            in[x]--;
            if (in[x] == 0 && !vis[x]){
                q.push(x);
                vis[x] = 1;
            }
        }
    }

    cout<<"\n ans : ";
    for (int x : ans)    
        cout<<x<<", ";
    cout<<endl;
    return ans;
}

int main(){

    addEdge(4, 1);
    addEdge(4, 0);
    addEdge(5, 0);
    addEdge(5, 2);
    addEdge(2, 3);
    addEdge(3, 1);
    addEdge(1, 2);
    
    // addEdge(1, 2);
    // addEdge(1, 3);
    // addEdge(2, 3);
    // addEdge(1, 4);
    // addEdge(4, 3);
    // addEdge(4, 5);
    // addEdge(3, 5);


    vector<int> res = topologicalSort();

    if (res.size() != n)
        cout<<"\nThere is a cycle ";
    else
    {
        cout<<"No cycle";
    }
    
    cout<<"\nResult size is "<<res.size();


    // for (int i = 0; i < 6; ++i){
    //     cout<<i<<" --> ";
    //     for (int x : g[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    

    return 0;
}

