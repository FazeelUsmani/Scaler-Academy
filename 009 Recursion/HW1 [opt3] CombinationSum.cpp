vector<vector<int> > ans;

void recurse(vector<int> &A, int B, vector<int> &curr, int sum, int index){
    
    if (sum == B){
        ans.push_back(curr);
        return;
    }
    if (sum > B)
        return;
        
    unordered_map<int,int> freq;
    for (int i = index; i < A.size(); i++){
        if (freq[A[i]] == 0){
            freq[A[i]] = 1;
            curr.push_back(A[i]);
            recurse(A,B,curr,sum+A[i],i+1);
            curr.pop_back();
        }
    }
    
    return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    ans.clear();
    sort(A.begin(), A.end());
    vector<int> curr;
    recurse(A, B, curr, 0, 0);
    
    return ans;
}
