Matrix Median
Given a matrix of integers A of size N x M in which each row is sorted. Find an return the overall median of the matrix A. Note: No extra memory is allowed. Note: Rows are numbered from top to bottom and columns are numbered from left to right. 
Input Format
The first and only argument given is the integer matrix A.
Output Format
Return the overall median of the matrix A.
Constraints
1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example
Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17
Matrix=



class Solution:
	# @param A : list of list of integers
	# @return an integer
	def findMedian(self, A):
	    
	    row = len(A)
	    col = len(A[0])
        
        mat = []
        
        for i in range(row):
            for j in range(col):
                mat.append(A[i][j])
                
        mat.sort()
        
        n = len(mat)
        if n&1:
            return mat[(n-1)//2]
        return ( mat[n//2] + mat[(n//2)+1])//2
            
