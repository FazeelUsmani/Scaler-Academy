Asked in 6*Amazon, 4*Google, 4*Facebook, Microsoft, Uber, Bloomberg, AliBaba, Oracle, Wish, 45

### Length of largest consecutive elements:

# Q) Given an array, return the length of largest subsequence consisting of consecutive elements

# I/P: [13,4,3,1,2,5,6,13,12,11]

# O/P: 6 (as 1,2,3,4,5,6 is the longest consecutive subsequence of length 6)


# Brute Force: would be generate all subsequences in O(2^n)      --> T.C: O(2^n)

# Sorting: Sort the array and then check for consecutives        --> T.C: O(nlog n)   

# Max & Min: Calculate min and max and start from min to max element and search in set containing all array elements
# for the consecutives. Maintain the count for the max.                                     --> T.C: O(max-min)


# How we can define a streak/ consecutive elements uniquely?
# By left & right border

A = [13,4,3,1,2,5,6,13,12,11]

# Check for 13 can be a streak for the longest subsequence. Is it a left boundary?
# No because

# For any element x, if x-1 not present then it is the left boundary for any one longest subsequence.

# All elements are checked at max twice, one checked for left boundary or not, other time to check is a consecutive element or not

# --> T.C: O(n)
# --> S.C: O(n)


arr = [13,4,3,1,12,2,11,5,6]

def LargestConsecutiveSubsequence(arr):
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
 

print(LargestConsecutiveSubsequence(arr))









