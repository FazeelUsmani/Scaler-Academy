const int maxn = 100009;
int vis[maxn];
int recStack[maxn];
vector<int> adj[maxn];

bool isCyclic(int v){
    
    if (vis[v] == 0){
        vis[v] = 1;
        recStack[v] = 1;
        
        for (int edge: adj[v]){
            if (!vis[edge] && isCyclic(edge))
                return true;
            else if (recStack[edge])
                return true;
        }
    }
    recStack[v] = 0;
    return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    memset(vis, 0, sizeof(vis));
    memset(recStack, 0, sizeof(recStack));
    for (int i = 0; i < maxn; ++i)
        adj[i].clear();
        
    for (auto it : B)
        adj[it[0]].push_back(it[1]);
    int flag = 0;
    for (int i = 1; i <= A; ++i){
        if (vis[i] == 0 && isCyclic(i))
            return 1;
    }
    return 0;
}
