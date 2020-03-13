Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence. 

Example: Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. 
Return its length: 4. Your algorithm should run in O(n) complexity.


class Solution:
	# @param A : tuple of integers
	# @return an integer
	def longestConsecutive(self, arr):
	    x = set()
        n = len(arr)
        
        for i in range(n):
            x.add(arr[i])
        
        maxCnt = -1
        
        for i in range(n):
            t = arr[i]
            if t-1 not in x:      
                cnt = 0
                k = 0
                
                while True:        
                    if t+k in x:
                        cnt += 1
                    else:
                        maxCnt = max(maxCnt, cnt)
                        break
                    k += 1
        
        return maxCnt
