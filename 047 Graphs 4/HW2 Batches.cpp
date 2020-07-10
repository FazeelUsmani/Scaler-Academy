const int MAXN = 1e5 + 7, MOD = 1e9 + 7;
int n, m;
unordered_set<int> uset;
int p[MAXN], sz[MAXN];

void reset(){
    uset.clear();
    for(int i = 0; i < MAXN; ++i){
        p[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    while (x != p[x])
        x = p[x];
    return x;
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}

bool same(int a,int b){
    return find(a) == find(b);
}


int Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    reset();
    n = A;
    m = B.size();
    for (int i = 0; i < m; ++i){
        int u = B[i][0], v = B[i][1];
        uset.insert(u);
        uset.insert(v);
        if (!same(u, v))
            merge(u, v);
    }
    
    bool flag = false;
    m = C.size();
    for (int i = 0; i < m; ++i){
        int u = C[i][0], v = C[i][1];
        if (uset.find(u) != uset.end())
            flag = true;
        if (uset.find(u) != uset.end())
            flag = true;
        if (!same(u, v))
            merge(u, v);
    }
    
    if (flag)
        return 0;
    
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        cnt += (p[i] == i);
    
    int ans = 1;
    for (int i = 0; i < cnt; ++i)
        ans = (ans * 2) % MOD;
        
    return ans;
}
