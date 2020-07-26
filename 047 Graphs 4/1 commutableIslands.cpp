int find (int parent[], int node){
    
    while (node != parent[node]){
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    
    return node;
  
//     if (node == parent[node])
//         return node;
//     parent[node] = find(parent, parent[node]);
    
//     return parent[node];
}

bool myCmp(vector<int> x, vector<int> y){
    
    return x[2] < y[2];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    if (B.size() == 1)
        return B[0][2];
    
    sort(B.begin(), B.end(), myCmp);
    
    int parent[A+1], size[A+1];

    for (int i = 0; i <= A; ++i){
        parent[i] = i;
        size[i] = 1;
    }

    int i = 0, cost = 0, edgeCnt = 0;
    
    while ( (i < B.size()) && (edgeCnt + 1 < B.size()) ){
        int c = find(parent, B[i][0]);
        int d = find(parent, B[i][1]);
        
        if (c != d){
            if (size[c] < size[d])
                swap(c, d);
                
            parent[d] = c;
            size[c] += size[d];
            cost += B[i][2];
            edgeCnt++;
        }
        ++i;
    }
    
    return cost;
}
