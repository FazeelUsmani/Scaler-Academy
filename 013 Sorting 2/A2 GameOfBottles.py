Game of Bottles
Problem Description
Given an array of integers A of size N which denotes N cylindrical empty bottles. The radius of the ith bottle is A[i]. You can put the ith bottle into the jth bottle if the following conditions are met:
ith bottle is not put into another bottle.
jth bottle dosen't contain any other bottle.
The radius of bottle i is smaller than bottle j (A[i] < A[j]).
You can put bottles into each other any number of times. You want to MINIMIZE the number of visible bottles. A bottle is called visible if it is not put into any other bottle. Find and return the minimum number of visible bottles.


Problem Constraints
1 <= N <= 100000 1<= A[i] <= 100000000 


Input Format
First argument is an integer array A denoting the radius of the cyclindrical bottles.


Output Format
Return a single integer corresponding to the minimum number of visible bottles.


Example Input
A = [1, 2, 3]


Example Output
1


Example Explanation
In example it is possible to put bottle 1 into bottle 2, and 2 into 3.




class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        _max = -999999
        
        A.sort()
        cnt = 0
        ele = A[0]
        
        for i in range(len(A)):
            if ele == A[i]:
                cnt += 1
            else:
                cnt = 0
                ele = A[i]
                cnt += 1
                
            _max = max(_max, cnt)
                
        return _max
