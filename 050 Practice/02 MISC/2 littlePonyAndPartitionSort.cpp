int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> maxLeft(n, 0), minRight(n, 0);
    
    int currMax = INT_MIN;
    for (int i = 0; i < n; ++i){
        maxLeft[i] = max(currMax, A[i]);
        currMax = max(currMax, maxLeft[i]);
    }
    
    int currMin = INT_MAX;
    for (int i = n-1; i >= 0; --i){
        minRight[i] = min(currMin, A[i]);
        currMin = min(currMin, minRight[i]);
    }
        
    int partitions = 1;
    for (int i = 0; i < n-1; ++i){
        if (maxLeft[i] <= minRight[i+1]){
            partitions++;
        }
    }
    
    
    return partitions;
}
