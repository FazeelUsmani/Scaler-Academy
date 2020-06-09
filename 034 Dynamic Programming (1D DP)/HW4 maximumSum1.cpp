int Solution::solve(vector<int> &A, int B, int C, int D) {
    
    int n = A.size();
    vector<int> left(n, 0), right(n, 0);

    left[0] = B*A[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i-1], B*A[i]);

    right[n-1] = D*A[n-1];
    for (int i = n-2; i >= 0; i--)
        right[i] = max(right[i+1], D*A[i]);

    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        ans = max(ans, left[i] + C*A[i] + right[i]);
    }

    return ans;
}
