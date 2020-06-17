
int ncrdp(int n, int r, int mod){

    int C[n+1][r+1];
    memset(C, 0, sizeof(C));

    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= min(i,r); ++j){
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
            {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
    
    return C[n][r] % mod;
}
