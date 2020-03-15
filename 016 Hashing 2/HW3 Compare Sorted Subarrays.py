Compare Sorted Subarrays
Given an array A of length N. You have to answer Q queires. Each query will contain 4 integers l1, r1, l2 and r2.
If sorted segment from [l1, r1] is same as sorted segment from [l2 r2] then answer is 1 else 0.
NOTE - The queries are 0-indexed.

Input:
1st will be array A. 2nd will be 2-D array denoting queries with dimension Q * 4. 
Consider ith query as Arr[i][0], Arr[i][1], Arr[i][2] and Arr[i][3]. 

Output:
Return an array of length Q with answer of the queries in the same order in input. 

Constraint:
0 <= A[i] <= 100000
1 <= N <= 100000
1 <= Q <= 100000

Example:
Input:
A = [1 7 11 8 11 7 1]
Q = [[0 2 4 6]] 

Output:
[1]

Explanation:
(0, 2) -> [1 7 11]
(4, 6) -> [11 7 1]
Both are same when sorted hence 1.



import random

N = 100000
INF = 1<<46
Hash = {}

def rand46():
  ret = 0
  ret |= random.randint(0, INF)
  x = random.randint(0, INF)
  ret |= (x<<15)
  
  return ret

def set_hash(a):
  n = len(a)
  for i in range(n):
    if ( Hash.get(a[i]) == None ):
      Hash[ a[i] ] = rand46()

class Solution:
	def solve(self, A, B):
	      n = len(A)
          set_hash(A)
          pre = [0]*n
          pre[0] = Hash[ A[0] ]
        
          for i in range(1, n):
            pre[i] = pre[i-1] + Hash[ A[i] ]
        
          lenB = len(B)
          ans = [0]*lenB
          for i in range(lenB):
            l1, r1 = B[i][0], B[i][1]
            l2, r2 = B[i][2], B[i][3]
        
            if l1 > 0:
              sum1 = pre[r1] - pre[l1-1]
            else:
              sum1 = pre[r1]
            
            if l2 > 0:
              sum2 = pre[r2] - pre[ l2 - 1]
            else:
              sum2 = pre[r2]
        
            if sum1 == sum2:
              ans[i] = 1
            else:
              ans[i] = 0
        
          return ans
