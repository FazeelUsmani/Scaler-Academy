const int maxn = 100000;
int vis[maxn];
int in[maxn];
vector<int> adj[maxn];

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    for (int i = 0; i < maxn; ++i)
        adj[i].clear();
    
    for (int i = 0; i < B.size(); ++i){
        adj[B[i]].push_back(C[i]);
    }
    
    for (int i = 1; i <= A; ++i){
        for (int x : adj[i]){
            in[x]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= A; ++i){
        if (in[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }
    
    int ans = 0;
    while (!q.empty()){
        int temp = q.front();
        q.pop();
        ans++;
        for (int x : adj[temp]){
            in[x]--;
            if (in[x] == 0 && !vis[x]){
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    
    if (ans == A)   
        return 1;
    return 0;
}
