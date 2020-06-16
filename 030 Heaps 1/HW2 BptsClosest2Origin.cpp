

bool compare(vector<int> p1, vector<int> p2){
    int d1 = p1[0]*p1[0] + p1[1]*p1[1];
    int d2 = p2[0]*p2[0] + p2[1]*p2[1];
    
    return d1 < d2;
}

vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    
    sort(A.begin(), A.end(), compare);
    priority_queue <int, vector<int>, compare> pq(A.begin(), A.end(), compare);
    
    vector<vector<int>> ans;
    
    while (A.size() - B){
        A.pop_back();
    }
    
    return A;
}
