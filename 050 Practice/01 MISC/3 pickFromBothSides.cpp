int Solution::solve(vector<int> &A, int B) {
    
    int maxSum = INT_MIN;
    int sum = 0;
    int n = A.size();
    
    for (int i = n - 1; i >= n-B; --i){
        sum += A[i];
    }
    maxSum = max(maxSum, sum);
    int i = 0, j = n - B;
    
    while (j < n){
        sum = sum - A[j++] + A[i++];
        maxSum = max(maxSum, sum);
    }
    
    return maxSum;
}
