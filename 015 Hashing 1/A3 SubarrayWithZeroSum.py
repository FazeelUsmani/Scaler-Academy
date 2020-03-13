Find if there is a sub-array with 0 sum
Given an array of integers A, find and return whether the given array contains a subarray with a sum equal to 0. 
If the given array contains a sub-array with sum zero return 1 else return 0. Note: Length of sub array should be at least one. 
Input Format
The only argument given is the integer array A.
Output Format
Return whether the given array contains a subarray with a sum equal to **0**.
Constraints
1 <= length of the array <= 100000
-10^9 <= A[i] <= 10^9 
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    0

Input 2:
    A = [5, 17, -22, 11]
Output 2:
    1
    
    
    
class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, arr):
        n = len(arr)
        x = set()
        pre = arr[0]
        currSum = 0
        x.add(pre)
        
        for i in range(1,n):    
            currSum = pre + arr[i]
            if currSum == 0:        
                return 1
            if currSum in x:
                return 1
            else:
                x.add(currSum)
            pre = currSum
        
        return 0
        
       
       
   
