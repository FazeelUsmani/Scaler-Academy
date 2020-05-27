/*

N max pair combinations

Problem Description
Given two integers arrays A and B of size N each. Find the maximum N elements from the sum combinations (Ai + Bj) 
formed from elements in array A and B. 


Problem Constraints
1 <= N <= 2 * 105 -1000 <= A[i], B[i] <= 1000 


Input Format
First argument is an integer array A.
Second argument is an integer array B.


Output Format
Return an intger array denoting the N maximum element in descending order.


Example Input
Input 1:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
Input 2:
 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]


Example Output
Output 1:
 [10, 9, 9, 8]
Output 2:
 [8, 6, 6, 5]


Example Explanation
Explanation 1:
 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
Explanation 2:
 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).


*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int,int>> S;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    pq.push(make_pair(A[n-1]+B[n-1], make_pair(n-1,n-1)));
    S.insert(make_pair(n-1,n-1));
    
    vector<int> ans;
    int k = n;
    
    while (k--){
        pair<int, pair<int,int>> top = pq.top();
        pq.pop();
        
        ans.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;
        
        if (L>=0 && R>0 && S.find(make_pair(L,R-1)) == S.end() ){
            pq.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
            S.insert(make_pair(L,R-1));
        }
        
        if ( L>0 && R>=0 && S.find(make_pair(L-1, R)) == S.end()){
            pq.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
            S.insert(make_pair(L-1,R));
        }
        
    }
    
    return ans;
}
