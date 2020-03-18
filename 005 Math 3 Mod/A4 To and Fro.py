To and Fro
Problem Description
The Guardians of the Galaxy have just landed on Earth. There are N cities in a row numbered from 1 to N. The cost of going from a city with number i to a city with number j is the remainder when (i+j) is divided by (n+1). The Guardians want to visit every city but in the minimum cost. What is the minimum cost that will be incurred? 


Problem Constraints
1 <= N <= 10000000


Input Format
A single integer N denoting the number of cities.


Output Format
Minimum cost to be able to travel to each city


Example Input
 3


Example Output
 1


Example Explanation
 Tour would be 1 -> 3 -> 2
 
 
class Solution:
    # @param A : integer
    # @return an integer
    def solve(self, A):
        
        return A//2 - (A%2==0)
