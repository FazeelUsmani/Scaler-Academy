long long MOD = 1000000007;

int Solution::cntBits(vector<int> &A) {
    
    long long cnt = 0, ans = 0;
    for (int i = 0; i < 32; ++i) {
        cnt = 0;
        for (int j = 0; j < A.size(); ++j) {
            if (A[j] & (1<<i)) {
                cnt++;
            }
        }  
        cnt %= MOD;
        ans = (ans + 2*cnt*(A.size()-cnt)) % MOD;
    }
    
    return ans % MOD;
}
