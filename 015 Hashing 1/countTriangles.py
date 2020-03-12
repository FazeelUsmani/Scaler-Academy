# Find the count of right angled triangle such that the base and perpendicular are parallel to either X or Y-axis? 

# Given two arrays of integers A and B of size N each, where each pair (A[i], B[i]) for 0 <= i < N
# represents a unique point (x, y) in 2D Cartesian plane.

# Find and return the number of unordered triplets (i, j, k) such that (A[i], B[i]), (A[j], B[j]) and (A[k], B[k])
# form a right angled triangle with the triangle having one side parallel to the x-axis and one side parallel to the y-axis.

# Note: The answer may be large so return the answer modulo (10^9 + 7).

# Here is the link of the problem on InterviewBit: https://www.interviewbit.com/problems/count-right-triangles



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
                
        
