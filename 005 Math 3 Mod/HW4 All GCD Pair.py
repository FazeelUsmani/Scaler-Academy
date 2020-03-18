ALL GCD PAIR
Problem Description
Given an array of integers A of size N containing GCD of every possible pair of elements of another array. Find and return the original numbers which are used to calculate the GCD array in any order. For example, if original numbers are {2, 8, 10} then the given array will be {2, 2, 2, 2, 8, 2, 2, 2, 10}.    


Problem Constraints
1 <= N <= 10000
1 <= A[i] <= 1e9


Input Format
The first and only argument given is the integer array A.


Output Format
Find and return the original numbers which are used to calculate the GCD array in any order.


Example Input
Input 1: 
 A = [2, 2, 2, 2, 8, 2, 2, 2, 10]
 Input 2:
 A = [5, 5, 5, 15]
 


Example Output
Output 1:
 [2, 8, 10]
Output 2:
 [5, 15]
 


Example Explanation
Explanation 1:
 Initially, array A = [2, 2, 2, 2, 8, 2, 2, 2, 10].
 2 is the gcd between 2 and 8, 2 and 10.
 8 and 10 are the gcds pair with itself.
 Therefore, [2, 8, 10] is the original array
 
 
 
 
class Solution:
    
    def gcd(self, a, b):
        if a == b == 0:
            return -1
            
        if b == 0:
            return a
        return self.gcd(b, a%b)
        
    
    def solve(self, A):
        
        n = len(A)
        A.sort(reverse = True)
        
        freq = {}
        
        for i in range(n):
            if A[i] in freq:
                freq[A[i]] += 1
            else:
                freq[A[i]] = 1
                
        ans = []
        for i in range(n):
            if freq[A[i]] != 0:
                ans.append(A[i])
                freq[A[i]] -= 1
                
                l = len(ans) - 1
                if l == n-1:
                    return ans
                
                for j in range(l):
                    x = self.gcd(A[i], ans[j])
                    freq[x] -= 2
                    
        return ans
                
            
        
        
        
        
