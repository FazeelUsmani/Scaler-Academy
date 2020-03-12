# 1) Given an array, Return True if there exists a sub array such that sum of elements of subarray is zero else False

arr = [2,4,-3,-1,5,-1]

def subarray(arr):  
  n = len(arr)
  x = set()
  pre = arr[0]
  currSum = 0
  x.add(pre)
  for i in range(1,n):    
    currSum = pre + arr[i]
    if currSum == 0:        # Because the prefix Sum is 0 iff the sum of elements from 0 to that element is 0
      return True
    if currSum in x:
      return True
    else:
      x.add(currSum)
    
    pre = currSum
  
  return False


print(subarray(arr))


_______________________________________________________________________________________________________

# 2) Given an array, return the length of longest subarray of sum zero

# Create a dictionary of prefixSum and the first occurance index of an element

arr = [2,4,-3,-1,5,-1]

def subarray1(arr):
  n = len(arr)
  dict = {}
  pre = arr[0]
  currSum = 0
  maxLength = -1
  dict[pre] = 0

  for i in range(1, n):
    
    currSum = pre + arr[i]
    if currSum in dict:
      maxLength = max(maxLength, i - dict[currSum] )
    else:
      dict[currSum] = i
      
    pre = currSum

  return maxLength

print(subarray1(arr))



# What if the input array is [5,-4,-1]? Does the above solution work?
# a) No, isn't it? This is the corner case you need to handle it

arr = [5,-4,-1,7]

def subarray1(arr):
  n = len(arr)
  dict = {}
  pre = arr[0]
  currSum = 0
  maxLength = -1
  dict[pre] = 0

  for i in range(1, n):
         
    currSum = pre + arr[i]

    if currSum == 0:                              # I have added these two lines of code to handle cornercase
      maxLength = max(maxLength, i+1)
    
    if currSum in dict:
      maxLength = max(maxLength, i - dict[currSum] )
    else:
      dict[currSum] = i
    pre = currSum

  return maxLength

print(subarray1(arr))

_______________________________________________________________________________________________________


# 3) Given an array, find the length of the largest subarray sum = k


arr = [12, -8, 4, -6, 3, 2, 2, -2]
k = 1

def largestSubarraySum(arr, k):
  n = len(arr)
  pre = arr[0]

  if k-pre == arr[0]:
    maxLength = 1
  else:
    maxLength = 0

  dict = {}
  dict[ arr[0] ] = 0

  for i in range(1, n):
    pre += arr[i]

    if (k-pre) in dict:
      maxLength = max(maxLength, i-dict[k-pre]+1)
    else:
      dict[ arr[i] ] = i

  return maxLength

print(largestSubarraySum(arr, k))


_______________________________________________________________________________________________________


# 4) Given an array, find special pair a[i], a[j] such that a[i] == a[j] and |i-j] is minimum. 
# You need to return i, j and the min distance


arr = [2,4,6,2,3,2,3]

def specialPair(arr):

  dict = {}
  n = len(arr)
  minDist = 9999

  for i in range(n):
    if arr[i] in dict:

      minDist = min(minDist, i-dict[ arr[i] ])
      i_idx = dict[ arr[i] ]
      j_idx = i
      dict[ arr[i] ] = i

    else:
      dict[ arr[i] ] = i

  return i_idx, j_idx, minDist

print(specialPair(arr))

_______________________________________________________________________________________________________
