
#define pp pair<int, int>

int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    priority_queue <pp, vector<pp>, greater<pp> > pq;
    
    vector<int> state = A;
    
    for (int i = 0; i < n; ++i)
        pq.push({2*A[i], i});
    
    while (B--){
        pp temp = pq.top();
        pq.pop();
        state[temp.second] = temp.first;
        pq.push({state[temp.second]+A[temp.second], temp.second});
    }
    
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i)
        ans = max(ans, state[i]);
        
    return ans;
}
