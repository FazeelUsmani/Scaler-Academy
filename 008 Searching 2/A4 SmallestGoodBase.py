Smallest Good Base
Given an integer A, we call k >= 2 a good base of A, if all digits of A base k are 1. Now given a string representing A, you should return the smallest good base of A in string format. 
Input Format
The only argument given is the string representing A.
Output Format
Return the smallest good base of A in string format.
Constraints
3 <= A <= 10^18
For Example
Input 1:
    A = "13"
Output 1:
    "3"     (13 in base 3 is 111)

Input 2:
    A = "4681"
Output 2:
    "8"     (4681 in base 8 is 11111)
    
    
    
    
class Solution:

            
    def solve(self, A):
        
        N = int(A)

        for i in range(63,0,-1):
            low = 2
            high = N-1
            
            while low<=high:
                
                mid = low + (high-low)//2
                sum = (mid**i-1)//(mid-1)
                
                if sum == N:
                    return str(mid)
                    
                elif sum > N:
                    high = mid-1
                    
                else:
                    low = mid+1
                    
             
                    
                    
