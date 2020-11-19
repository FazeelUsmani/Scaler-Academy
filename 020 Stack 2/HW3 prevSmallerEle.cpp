vector<int> Solution::prevSmaller(vector<int> &A) {
    
    int n = A.size();
    if (n == 0)
        return {};
    if (n == 1)
        return {-1};
        
    stack<int> s;
    s.push(0);
    int i = 1;
    vector<int> ans;
    ans.push_back(-1);
    
    while (i < n) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        
        if (s.empty())
            ans.push_back(-1);
        else 
            ans.push_back(A[s.top()]);
        s.push(i);
        ++i;
    }
    
    return ans;
}
