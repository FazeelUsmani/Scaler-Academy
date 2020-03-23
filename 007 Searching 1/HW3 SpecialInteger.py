Special Integer
Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with sum of elements greater than B. 
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the maximum value of K (sub array length).
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9
1 <= B <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 10
Output 1:
    2

Input 2:
    A = [5, 17, 100, 11]
    B = 130
Output 2:
    3
    
    
class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    
    
    def isPossible(self, A, mid, B, P):
        
            
        for i in range(mid-1, len(A)):
            if i-mid < 0:
                x = 0
                
            else:
                x = P[i-mid]
            
            if P[i] - x > B:
                return False
        
        return True
    
    def solve(self, A, B):
        
        left = 0
        right = len(A)+1
        
        P = [0 for i in range(len(A))]
        P[0] = A[0]
        
        for i in range(1, len(A)):
            P[i] = P[i-1] + A[i]
        
        while (right-left) > 1:
            mid = left + (right-left)//2
            
            if self.isPossible(A, mid, B, P):
                left = mid
            else:
                right = mid
        
        return left
            
