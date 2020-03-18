Grid Unique Paths
Problem Description
A robot is located at the top-left corner of an A x B grid (marked 'Start' in the diagram below).  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below). How many possible unique paths are there? 


Problem Constraints
A and B will be such that the resulting answer fits in a 32 bit signed integer.


Input Format
First argument of input will be single integer A.
Second argument of input will be single integer B.


Output Format
Return a single integer denoting the number of unique paths.


Example Input
 A = 2, B = 2


Example Output
 2


Example Explanation
 2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              
              
 
class Solution:
	
	def uniquePaths(self, A, B):
	    
	    if A == 1 or B == 1:
	        return 1
	        
	    if A<B:
	        A,B = B,A
        
        res = 1
        j = 1
        	       
	    for i in range(A, A+B-2+1, 1):
	        res *= i
	        res //= j
	        j += 1
	        
	    return res
	    
