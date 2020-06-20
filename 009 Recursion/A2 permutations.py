class Solution:
	# @param A : list of integers
	# @return a list of list of integers
	def permute(self, A):
	    
	    if len(A)==1:
	        return [A]
	        
	    ans = []
	    for i in range(len(A)):
	        remString = A[:i]+A[i+1:]
	        p = self.permute(remString)
	        
	        for j in range(len(p)):
	            ans.append([A[i]]+p[j])
	            
	    return ans
	    
