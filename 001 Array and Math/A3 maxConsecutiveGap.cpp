int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    
    if (n < 2)
        return 0;
    
    int maxEle = INT_MIN;
    int minEle = INT_MAX;
    
    for (int x: A) {
        maxEle = max(maxEle, x);
        minEle = min(minEle, x);
    }
    
    int gap = (maxEle - minEle - 1)/(n-1) + 1;
    
    vector<int> minB(n-1, INT_MAX);
    vector<int> maxB(n-1, INT_MIN);
    
    for (int i = 0; i < n; ++i) {
        if ( (A[i] != maxEle) && (A[i] != minEle) ) {
            int index = (A[i]-minEle)/gap;
            minB[index] = min(minB[index], A[i]);
            maxB[index] = max(maxB[index], A[i]);
        }
    }
    
    int ans = INT_MIN;
    int prev = minEle;
    for (int i = 0; i < n-1; ++i) {
        if ( (minB[i] == INT_MAX) && (maxB[i] == INT_MIN) ) {
            continue;
        }
        ans = max(ans, minB[i]-prev);
        prev = maxB[i];
    }
    ans = max(ans, maxEle - prev);
    
    return ans;
}
