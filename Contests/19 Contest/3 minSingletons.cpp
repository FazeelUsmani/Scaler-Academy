/*

Minimum Singletons
Problem Description

You have two permutations A and B of size N. A permutation is a sequence in which every number from 1 to N appears exactly once. Inititally, all the numbers from 1 to N appear once. But you want to minimize the count of numbers which appear only once.

For that, you can do some operations. In one operation, you can select an index i (0 <= i <= N - 1) and swap A[i] and B[i]. You can do as many operations as you like.

Find the minimum count of numbers that appear only once in A by doing any number of operations.



Problem Constraints
1 <= N <= 2 x 105

A and B are permutations of length N



Input Format
The first and second argument contains two permutations A and B respectively.



Output Format
Return the minimum count of numbers that appear only once in A by doing any number of operations.


Example Input
Input 1:

  A : [ 3, 7, 6, 2, 1, 4, 5 ]
  B : [ 4, 6, 5, 1, 7, 2, 3 ]
Input 2:

  A : [ 3, 4, 1, 2 ]
  B : [ 3, 4, 1, 2 ]


Example Output
Output 1:

  1
Output 2:

  4


Example Explanation
Explanation 1:

  We can do an operation at 1, 3 and 6 to get the optimal result.
  The final arrays will be-
  A : [3, 6, 6, 1, 1, 4, 3]
  B : [4, 7, 5, 2, 7, 2, 5]
Explanation 2:

  Doing any opertaion does not change anything.

*/