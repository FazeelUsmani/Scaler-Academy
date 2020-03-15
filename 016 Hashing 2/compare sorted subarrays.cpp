vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    
    vector<int> res;
    int n = A.size();
    // Prefix Sum
    vector<int> pre(n,0);
    pre[0] = A[0];
    for (int i = 1 ; i < A.size(); i++)
        pre[i] = pre[i-1] + A[i];
    
        
    
    for (int i = 0; i < B.size(); i++){
        int ans = false;
        int l1 = B[i][0];
        int r1 = B[i][1];
        int l2 = B[i][2];
        int r2 = B[i][3];
        
        int sum1 = pre[r1];
        if (l1 > 0)
            sum1 -= pre[l1-1];
            
        int sum2 = pre[r2];
        if (l2 > 0)
            sum2 -= pre[l2-1];
            
        if (sum1 == sum2){
            ans = true;
            unordered_map<int, int> umap;
            for (int j = l1; j <= r1; j++)
                umap[ A[j] ]++;
            for (int j = l2; j <= r2; j++)    
                umap[ A[j] ]--;
                
            for (auto itr = umap.begin(); itr != umap.end(); itr++)
                if (itr->second != 0)
                    ans = false;
        }
            
        res.push_back(ans);
    }
    
    return res;
}
