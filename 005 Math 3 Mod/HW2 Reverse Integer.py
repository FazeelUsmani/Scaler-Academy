Reverse integer
Problem Description
You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer

Look at the example for clarification.


Problem Constraints
N belongs to the Integer limits.


Input Format
Input an Integer.


Output Format
Return a single integer denoting the reverse of the given integer.


Example Input
Input 1:
 x = 123

Input 2:
 x = -123
      


Example Output
Output 1:
 321

Ouput 2:
 -321
    


Example Explanation
 If the given integer is negative like -123 the output is also negative -321
 
 
 
 class Solution:
	def reverse(self, A):
	        negative = False
    
            if A < 0:
                negative = True
                A = -1*A
                
            rev = 0
            while A > 0:
                r = A % 10
                rev = rev*10 + r
                A //= 10
                
            if rev < -2147483648 or rev > 2147483647:
                return 0
                
            if negative:
                return -1*rev
            return rev
            
