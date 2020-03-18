Excel Column Title
Problem Description
Given a positive integer, return its corresponding column title as appear in an Excel sheet. For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
 


Problem Constraints
1 <= A <= INTMAX


Input Format
First and only argument of input contains single integer A


Output Format
Return a string denoting the corresponding title.


Example Input
 A = 27


Example Output
 "AA"


Example Explanation
    1 -> A,
    2 -> B,
    3 -> C,
    ...
    26 -> Z,
    27 -> AA,
    28 -> AB 
    
  


class Solution:
	# @param A : integer
	# @return a strings
	def convertToTitle(self, A):
	    
	    res = []

        while A > 0:
          if A % 26 == 0:
              res.append('Z')
              A//= 26
              A = A-1

          else:
              res.append(chr( (A%26) + 64))
              A //= 26
        
        s = ""
        s = s.join(res[::-1])
        
        return s

