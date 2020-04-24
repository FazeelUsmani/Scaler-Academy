Simplify Directory Path

Given a string A representing an absolute path for a file (Unix-style). 
Return the string A after simplifying the absolute path. Note:
Absolute path always begin with '/' ( root directory ).
Path will not have whitespace characters.

Input Format
The only argument given is string A.

Output Format
Return a string denoting the simplified absolue path for a file (Unix-style).

For Example
Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
    
    
 
class Solution:
	# @param A : string
	# @return a strings
	def simplifyPath(self, A):
	    
        A = A.split('/')
        stack = []
        
        for i in A:
          if i == '' or i == '.':
              continue
          
          elif i == '..':
              if (len(stack) != 0):
                  stack.pop()
                  
          else:
              stack.append(i)
             
        return '/'+'/'.join(stack)
        
	    
