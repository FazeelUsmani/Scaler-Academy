int Solution::solve(vector<vector<int> > &A) {
    
    sort(A.begin(), A.end());
    priority_queue <int, vector<int>, greater<int> > pq;
    
    pq.push(A[0][1]);
    int rooms = 1;
    
    for (int i = 1; i < A.size(); ++i){
        if (A[i][0] < pq.top())
            rooms++;
        else
            pq.pop();
        pq.push(A[i][1]);
    }
    
    return rooms;
}
