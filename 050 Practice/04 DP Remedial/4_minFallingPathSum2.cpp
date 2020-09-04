int Solution::solve(vector<vector<int> > &arr) {
    
    int m=arr.size(),n=arr[0].size();
    vector<vector<int> > dp(m,vector<int>(n));
    for(int i=0;i<n;i++){
        dp[m-1][i]=arr[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=0;j<n;j++){
            int ma=INT_MAX;
            for(int k=0;k<n;k++){
                if(k!=j){
                    ma=min(ma,dp[i+1][k]);
                }
            }
            dp[i][j]=arr[i][j]+ma;
        }
    }
    
    return *min_element(dp[0].begin(),dp[0].end());
}
