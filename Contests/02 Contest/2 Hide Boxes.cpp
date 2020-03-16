Hide boxes
Problem Description
There are N cubical boxes and the edge length of boxes is given by an array A of size N. 
A box can hold another box inside it, if and only if the length of a box is at least twice as large than another box. 
There can be atmost one box inside any other box. The box which is inside another box is not visible. 
You have to minimize the number of boxes visible.  


Problem Constraints
1 <= N <= 100000
1 <= A[i] <= 109


Input Format
First argument is an integer array A of size N.


Output Format
Return an integer denoting minimum number of boxes visible.


Example Input
 A = [1, 2, 2, 4, 3]


Example Output
 3


Example Explanation
 We can put the box at index 1 into box at index 5.Also, the box at index 2 into box at index 4. 
 So, the visible boxes will be the box at index 3,4,5.
 
 
 int Solution::solve(vector<int> &A) {
    
    int n  = A.size();
    sort(A.begin(), A.end());
    int i = 0, j = n/2, ans = n;
    
    while (i < n/2 && j < n){
        
        if (A[i]*2 <= A[j]){
            ans--;
            i++;
        }
        j++;
    }
    return ans;
}
