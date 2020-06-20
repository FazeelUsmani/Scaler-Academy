# Little Ponny and Subset Median

# Problem Description

# You are given an array A.
# Consider the sum of all the subsequences of this array (There are 2|A| subsequence of this array).
# Calculate the median of all these subarrays.
# Since the median can be a floating-point number, return 2* Median.



# Problem Constraints
# 1 <= |A| <= 100000

# Each element of the array is between 1 and 103 (inclusive)



# Input Format
# The first and only argument of the input is the array A



# Output Format
# Your function should return a single integer - 2 * Median of all subsequence sum.



# Example Input
# Input 1:

#  A: [2, 1, 3]
# Input 2:

#  A: [1, 1, 1]


# Example Output
# Output 1:

#  6
# Output 2:

#  3


# Example Explanation
# Explanation 1:

#  There are 8 subsequence of the given array:

# [], [2] , [1], [3], [2+1], [2+3], [1+3], [1+2+3].
# The list of subsequence sum will look like : [0, 2, 1, 3, 3, 5, 4, 6].
# If we sort this list, we will get: [0, 1, 2, 3, 3, 4, 5, 6].
# The Median of this array will be (3 + 3)/2 = 3, thus 2*Median = 6.

# Explanation 2:

#  There are 8 subsequence of the given array:

# [], [1] , [1], [1], [1+1], [1+1], [1+1], [1+1+1].
# The list of subsequence sum will look like : [0, 1, 1, 1, 2, 2, 2, 3].
# If we sort this list, we will get: [0, 1, 1, 1, 2, 2, 2, 3].
# The Median of this array will be (1 + 2)/2 = 1.5, thus 2*Median = 3.




class Solution:
    def solve(self, A):
        
        return sum(A)
