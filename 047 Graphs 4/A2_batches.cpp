#include<bits/stdc++.h>
using namespace std;
int find(int parent[], int node){
    if (parent[node] == node)
        return node;
    parent[node] = find(parent, parent[node]);
    
    return parent[node];
}

void unionNodes(int a, int b, int parent[], int size[]){
    int c = find(parent, a);
    int d = find(parent, b);
    
    if (c != d){
        if (size[c] < size[d])
            swap(c, d);
        parent[d] = c;
        size[c] += size[d];
    }
}

int solve(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    
    int parent[A+1], size[A+1];
    
    for (int i = 0; i <= A; ++i){
        parent[i] = i;
        size[i] = 1;
    }
    
    for (int i = 0; i < C.size(); ++i){
        unionNodes(C[i][0], C[i][1], parent, size);
    }
    
    unordered_map<int, int> umap;
    
    for (int i = 1; i <=A; ++i)
        umap[parent[i]] += B[i];
        
    int ans = 0;
        
    for (auto it : umap){
        if (it.second >= D){
            ans++;
        }
    }
    
    return ans;
}

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

int main(){

    int A = 9;
    vector<int> B = {10,8,2,3,4,8,3,5,9};
    vector<vector<int> > C = { {1,4}, {1, 6}, {2, 7}, {2, 9}, {3, 5}, {3, 8}, {4, 9}, {5, 8}, {6, 8} };
    int D = 25;

    cout<<solve(A, B, C, D);
}


int solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
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


