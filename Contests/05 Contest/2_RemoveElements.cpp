int Solution::solve(vector<int> &A) {
    long long n = A.size();
    sort(A.begin(), A.end());
    
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += A[i] % 1000000007;
    }
    
    long long ans = 0, mul = 1;
    for (int i = n-1; i >= 0; i--){
        ans = (ans + A[i]*mul) % 1000000007;
        mul++;
    }
    
    return ans;
}
