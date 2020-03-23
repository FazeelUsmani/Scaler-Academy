Maximum height of the staircase
Given an integer A representing the square blocks. The height of each square block is 1. The task is to create a staircase of max height using these blocks. The first stair would require only one block, the second stair would require two blocks and so on. Find and return the maximum height of the staircase. 
Input Format
The only argument given is integer A.
Output Format
Return the maximum height of the staircase using these blocks.
Constraints
0 <= A <= 10^9
For Example
Input 1:
    A = 10
Output 1:
    4

Input 2:
    A = 20
Output 2:
    5
    
    
    
    
class Solution:
    # @param A : integer
    # @return an integer
    def solve(self, A):
        
        # Most Optimized Solution: O(log(A))
        
        if A == 0: return 0
        
        low = 1
        high = A
        
        while high-low > 1:
            
            mid = low + (high-low)//2
            x = mid*(mid+1)//2
            
            if x == A:
                return mid
            elif x > A:
                high = mid
            else:
                low = mid
                
        return low
        
        
        
        
        # # Brute Force 2: Checking with sum of n numbers formula n*(n+1)//2  T.C: O(A)
        # if A == 0:
        #     return 0
        # i=1
        # while i <= A:
        #     x = (i*(i+1))//2
        #     if x > A:
        #         return i-1
        #     i += 1
        # return i-1
        
        
        
        # Brute Force 1 (optimized): O(A)
        # curr=1
        # while curr<=A:
        #     A -= curr
        #     curr += 1
        # return curr-1
       
       
        # Brute Force 1:   O(A)
        # i = 1
        # cnt = 0
        
        # while A>0:
        #     A = A-i
        #     cnt += 1
        #     i += 1
            
        #     if A < 0:
        #         return cnt-1
                
        # return cnt
            
            
