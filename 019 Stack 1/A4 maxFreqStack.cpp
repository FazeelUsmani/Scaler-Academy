unordered_map <int, int> freq;
unordered_map<int, stack<int>> s;
int maxFreq = 0;

void push(int ele, vector<int> &ans){
    
    freq[ele]++;
    if (maxFreq < freq[ele])
        maxFreq = freq[ele];
        
    if (s.find(freq[ele]) != s.end() ){ // if stack exists
        s[freq[ele]].push(ele);
    }
    else{
        stack<int> st;
        st.push(ele);
        s[freq[ele]] = st;  // key-> freq; val = stack
    }
    
    ans.push_back(-1);
}

void pop(vector<int> &ans){
    
    int maxFreqEle = s[maxFreq].top();
    ans.push_back(maxFreqEle);
    s[maxFreq].pop();
    
    if (s[maxFreq].empty())
        maxFreq--;
        
    freq[maxFreqEle]--;
    
}

vector<int> Solution::solve(vector<vector<int> > &A) {
    
    maxFreq = 0;
    freq.clear();
    s.clear();
    int n = A.size();
    vector<int> ans;
    
    for (int i = 0; i < n; i++){
        if (A[i][0] == 1)
            push(A[i][1], ans);
        else
            pop(ans);
    }
    
    return ans;
}
