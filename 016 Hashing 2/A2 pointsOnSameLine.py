# Points on same line
# Problem Description

# Given two array of integers A and B describing a pair of (A[i], B[i]) coordinates in 2D plane. A[i] describe x coordinates of the ith point in 2D plane whereas B[i] describes the y-coordinate of the ith point in 2D plane.

# Find and return the maximum number of points which lie on the same line.

# Problem Constraints
# 1 <= (length of the array A = length of array B) <= 1000

# -105 <= A[i], B[i] <= 105

# Input Format
# First argument is an integer array A.
# Second argument is an integer array B.

# Output Format
# Return the maximum number of points which lie on the same line.

# Example Input
# Input 1:

#  A = [-1, 0, 1, 2, 3, 3]
#  B = [1, 0, 1, 2, 3, 4]
# Input 2:

#  A = [3, 1, 4, 5, 7, -9, -8, 6]
#  B = [4, -8, -3, -2, -1, 5, 7, -4]

# Example Output
# Output 1:

#  4
# Output 2:

#  2

# Example Explanation
# Explanation 1:

#  The maximum number of point which lie on same line are 4, those points are {0, 0}, {1, 1}, {2, 2}, {3, 3}.
# Explanation 2:

#  Any 2 points lie on a same line.


class Solution:
    def solve(self, A, B):
        
        n = len(A) 
        points = []
        for i in range(n):
            points.append([A[i], B[i]])
            
        if n<3: 
            return n 
  
        max_val=0
        
        for i in points: 
            d = {}  
            dups = 0
            cur_max = 0
            
            for j in points: 
                if i!=j: 
                    if j[0]==i[0]: #vertical line 
                        slope='inf'
                    else: 
                        slope=float(j[1]-i[1])/float(j[0]-i[0]) 
                    d[slope] = d.get(slope,0)+1
                    cur_max=max(cur_max, d[slope]) 
                else: 
                    dups+=1

            max_val=max(max_val, cur_max+dups) 
  
        return max_val 
        
        
