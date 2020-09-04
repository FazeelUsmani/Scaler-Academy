int Solution::maxcoin(vector<int> &A) {
    
    int n = A.size();
    int i, x, y, z;
    vector<vector<int> > maxVal(n, vector<int> (n, 0));
    
    for (int k = 0; k < n; ++k){
        for (int j = k; j < n; ++j){
            i = j-k;
            
            x = 0;
            if ((i+2)<=j)
                x = maxVal[i+2][j];
            
            y = 0;
            if ((i+1) <= (j-1))
                y = maxVal[i+1][j-1];
            
            z = 0;
            if (i<=(j-2))
                z = maxVal[i][j-2];
            
            maxVal[i][j] = max(A[i]+min(x,y), A[j]+min(y,z));
        }
    }
    
    return maxVal[0][n-1];
}
