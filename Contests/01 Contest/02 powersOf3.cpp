/*

Powers of 3

Problem Description
Given a positive integer A. Return an array of minimum length whose elements represent the powers of 3 and 
he sum of all the elements is equal to A. NOTE: If A cannot be represented as the sum of powers of 3, 
then return an array containing only -1. 


Problem Constraints
1 <= A <= 109


Input Format
Single argument is an integer A.


Output Format
Return an array of minimum length of powers of 3 whose elements sums to A.


Example Input
Input 1:
13
Input 2:
3


Example Output
Output 1:
 [1, 3, 9]
Output 2:
 [3]


Example Explanation
Explanation 1:
30 = 1, 31 = 3, 32 = 9.
Also, 1 + 3 + 9 = 13. Here A = 13 which can be represented as the sum of 1, 3 and 9.
*/

class Solution:
    # @param A : integer
    # @return a list of integers
    
    def solve(self, A):
        
        if A<3:
            return [-1]
            
        ans = []
        
        for i in range(30,-1,-1):
        
            x = 3**i
            
            while A-x>=0:
                A -= x
                ans.append(x)
                

        return ans
                
    
