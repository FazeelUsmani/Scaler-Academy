// DP based solution SC: O(1)

int Solution::candy(vector<int> &A) {
    
    int n = A.size();
    int up = 0, down = 0, ret = 1, peak = 0;
    
    for (int i = 1; i < n; ++i){
        if (A[i-1] < A[i]){
            peak = ++up;
            down = 0;
            ret += 1+up;
        }
        else if (A[i-1] == A[i]){
            up = 0;
            down = 0;
            peak = 0;
            ret += 1;
        }
        else{
            up = 0;
            down++;
            ret += 1 + down;
            if (peak >= down) 
                ret += -1;
        }
    }
    
    return ret;
}
