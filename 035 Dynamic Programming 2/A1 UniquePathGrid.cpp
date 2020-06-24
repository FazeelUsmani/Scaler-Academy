int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    int row = A.size();
    int col = A[0].size();
    
    if (A[0][0] == 1 || A[row-1][col-1] == 1)
        return 0;
    
    int uPath[row][col];
    
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            uPath[i][j] = 0;
            
            if (i == 0 && j == 0)
                uPath[i][j] = 1;
                
            if (A[i][j])
                continue;
                
            if (i > 0) 
                uPath[i][j] += uPath[i-1][j];
                
            if (j > 0)
                uPath[i][j] += uPath[i][j-1];
        }
    }
    
    return uPath[row-1][col-1];
}
