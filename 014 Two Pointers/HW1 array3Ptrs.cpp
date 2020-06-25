/*

Array 3 Pointers
Problem Description

You are given 3 sorted arrays A, B and C.

Find i, j, k such that : max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.

Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])).



Problem Constraints
0 <= len(A), len(B), len(c) <= 106

0 <= A[i], B[i], C[i] <= 107



Input Format
First argument is an integer array A.

Second argument is an integer array B.

Third argument is an integer array C.



Output Format
Return an single integer denoting the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])).



Example Input
Input 1:

 A = [1, 4, 10]
 B = [2, 15, 20]
 C = [10, 12]
Input 2:

 A = [3, 5, 6]
 B = [2]
 C = [3, 4]


Example Output
Output 1:

 5
Output 2:

 1


Example Explanation
Explanation 1:

 With 10 from A, 15 from B and 10 from C.
Explanation 2:

 With 3 from A, 2 from B and 3 from C

*/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int i = 0, j = 0, k = 0;
    
    int ans = INT_MAX, diff = INT_MAX;
    int _max = INT_MIN, _min = INT_MAX;
    
    while ( i < A.size() && j < B.size() && k < C.size()){
        
        _max = max(A[i], max(B[j], C[k]));
        _min = min(A[i], min(B[j], C[k]));
        
        diff  = _max - _min;
        
        ans = min(diff, ans);
        
        if (diff == 0){
            break;
        }
        
        if (A[i] == _min)
            i++;
        else if (B[j] == _min)
            j++;
        else
            k++;
    }
    
    return ans;
}
