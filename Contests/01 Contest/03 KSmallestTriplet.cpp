/*
    Similar to the Matrix Median problem
    Binary Search + finding the smallest element
    O(log(high-low))
    isPossible --> O(N^2 log N)
    
    Note: Prefix aray will help in linear computations but here we've 3 pointers. 
*/

bool isPossible(vector<int> &A, int mid, int B){
    
    int n = A.size();
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int val = mid - (A[i] + A[j]);
            if (val <= 0)
                break;
            auto it = lower_bound(A.begin(), A.end(), val);
            if (it == A.begin())
                continue;
            it--;
            int idx = it - A.begin();
            if (idx > j)
                cnt += idx - j;
        }
    }
    if (cnt < B)
        return true;
    return false;
}



int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    sort(A.begin(), A.end());
    int low = 1, high = INT_MAX;
    
    while (low <= high){
        int mid = low + ((high-low)/2);
        if (isPossible(A, mid, B))
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return high;
}
