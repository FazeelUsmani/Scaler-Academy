Count Right Triangles
Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) for 0 <= i < N 
represents a unique point (x, y) in 2D Cartesian plane. Find and return the number of unordered triplets (i, j, k) 
such that (A[i], B[i]), (A[j], B[j]) and (A[k], B[k]) form a right angled triangle with the triangle having one side 
parallel to the x-axis and one side parallel to the y-axis. Note: The answer may be large so return the answer modulo (10^9 + 7). 
Input Format
The first argument given is an integer array A.
The second argument given is the integer array B.
Output Format
Return the number of unordered triplets that form a right angled triangle modulo (10^9 + 7).
Constraints
1 <= N <= 100000
0 <= A[i], B[i] <= 10^9 
For Example
Input 1:
    A = [1, 1, 2]
    B = [1, 2, 1]
Output 1:
    1

Input 2:
    A = [1, 1, 2, 3, 3]
    B = [1, 2, 1, 2, 1]
Output 2:
    6
    
    
class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return an integer
    def solve(self, A, B):
        x,y = {}, {}
        n = len(A)
        
        for i in range(n):
            if A[i] in x:
                x[ A[i] ] += 1
            else:
                x[ A[i] ] = 1
                
            if B[i] in y:
                y[ B[i] ] += 1
            else:
                y[ B[i] ] = 1
                
        cnt = 0
        for i in range(n):
            n = x[ A[i] ]
            m = y[ B[i] ]
            
            cnt = (cnt + (n-1)*(m-1)) % 1000000007
            
        return cnt
                
