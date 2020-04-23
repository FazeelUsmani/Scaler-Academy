/*
Maximum Frequency stack
You are given a matrix A which represent operations of size N x 2. Assume initially you have a stack-like data structure you have to perform operations on it. Operations are of two types:
1 x: push an integer x onto the stack and return -1
2 0: remove and return the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the top of the stack is removed and returned.
A[i][0] describes the type of operation to be performed. A[i][1] describe the element x or 0 corresponding to the operation performed. 
Input Format
The only argument given is the integer array A.
Output Format
Return the array of integers denoting answer to each operation.
Constraints
1 <= N <= 100000
1 <= A[i][0] <= 2
0 <= A[i][1] <= 10^9
For Example
Input 1:
    A = A = [
            [1, 5]
            [1, 7]
            [1, 5]
            [1, 7]
            [1, 4]
            [1, 5]
            [2, 0]
            [2, 0]
            [2, 0]
            [2, 0]  ]
Output 1:
    [-1, -1, -1, -1, -1, -1, 5, 7, 5, 4]

Input 2:
    A = A = [   
            [1, 5]
            [2 0]
            [1 4]   ]
Output 2:
    [-1, 5, -1]
*/


multimap<int, int, greater_equal<int>> st;
unordered_map <int, int> freq;

void push(int x, vector<int> &ans){
    st.insert({++freq[x], x});
    ans.push_back(-1);
}

void pop(vector<int> &ans){
    int res = st.begin()->second;
    st.erase(st.begin());
    freq[res]--;
    ans.push_back(res);
}

vector<int> Solution::solve(vector<vector<int> > &A) {
    
    st.clear();
    freq.clear();
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
