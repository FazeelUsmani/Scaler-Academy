vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    vector<pair<long long, int>> v;
    int n = A.size();
    for (int i = 0; i < n; ++i){
        long long x=A[i][0];
        long long y=A[i][1];
        v.push_back({x*x+y*y, i});
    }
    
    priority_queue< pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > minHeap(v.begin(), v.end());
    
    vector<vector<int>> ans;
    for (int i = 0; i < B; ++i){
        pair<long long, int> val = minHeap.top();
        minHeap.pop();
        vector<int> temp = A[val.second];
        ans.push_back(temp);
    }
    
    return ans;
}
