

vector<int> Solution::solve(vector<int> &A) {
    
    int _min = INT_MAX, _max = INT_MIN, n = A.size();
    sort( A.begin(), A.end() );
    for ( auto x: A ){
        _min = min(x, _min);
        _max = max(x, _max);
    }
    
    int diff = 0, zero = 0;
    for ( int i = 1; i < n; i++){
        int t = A[i] - A[i-1];
        if ( t == 1 || t == 0 )
            zero++;
        else
            diff = min(diff, t);
    }
        
    vector<int> ans;
    ans.push_back( n - diff - zero );
    ans.push_back(_max - _min - n - 1);
    return ans;
}
