1) Given an array, Return True if there exists a sub array such that sum of elements of subarray is zero else False

arr = [2,4,-3,-1,5,-1]

def subarray(arr):  
  n = len(arr)
  x = set()
  pre = arr[0]
  currSum = 0
  x.add(pre)
  for i in range(1,n):    
    currSum = pre + arr[i]
    
    if currSum in x:
      return True
    else:
      x.add(currSum)
    
    pre = currSum
  
  return False


print(subarray(arr))
