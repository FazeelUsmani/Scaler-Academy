int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    int m = A.size(), n = A[0].size();
    if (m == 0 || n == 0)
        return 0;
    
    
    for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            
            if (i == m-1 && j == n-1) 
                A[i][j] = max(1, 1-A[i][j]);
                
            else if (i == m-1)
                A[i][j] = max(1, A[i][j+1] - A[i][j]);
                
            else if (j == n-1)
                A[i][j] = max(1, A[i+1][j] - A[i][j]);
                
            else
                A[i][j] = max(1, min(A[i][j+1], A[i+1][j]) - A[i][j]);
        }
    }
    
    return A[0][0];
}
