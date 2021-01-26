/*
Ways of coloring!

Problem Description

You are given a rooted tree containing N vertices numbered from 1 to N and rooted at vertex numbered 1.

Let's call vertex x a 1-ancestor of vertex y, if x is the parent of vertex y.

Let'c call vertex x a p-ancestor of vertex y, if vertex y has a 1-ancestor, and x is a (p-1)-ancestor of b's 1-ancestor.

You can color each vertex in any of the two possible colours {red, green}.

You need to find the total number of different ways to completely color the tree such that in each possible coloring every vertex has a different color assigned then its p-th ancestor.

Return the total number of ways modulo 109 + 7.

NOTE:

In the given tree the hierarchy starts from vertex numbered 1.
Two ways are consider different if there exist atleast one vertex that is colored with different colors.


Problem Constraints
1 <= N, p <= 105

1 <= A[i][0] , A[i][1] <= N



Input Format
First argument is an 2D integer array A of size (N - 1) x 2 where (A[i][0], A[i][1]) denotes an edge between vertex A[i][0] and vertex A[i][1].

Second argument is an integer B denoting the value of p i.e p = B.



Output Format
Return an single integer denoting the total number of different ways to color the tree under the above mentioned restriction modulo 109 + 7.



Example Input
Input 1:

 A = [  [1, 2]
        [2, 3]
        [3, 4]
        [1, 5]
     ]
 B = 1
Input 2:

 A = [  [1, 2]
        [2, 3]
     ]
 B = 2


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 So as mentioned in the problem heirarchy starts from vertex numbered 1.
 So (1-ancestor) of vertex 2 is vertex 1, (1-ancestor) of vertex 3 is vertex 2, (1-ancestor) of vertex 4 is vertex 3 and
 (1-ancestor) of vertex 5 is vertex 1.

 First way of coloring:
    Color vertex - 1 : Red
    Color vertex - 2 : Green
    Color vertex - 3 : Red
    Color vertex - 4 : Green
    Color vertex - 5 : Green
 Second way of coloring:
    Color vertex - 1 : Green
    Color vertex - 2 : Red
    Color vertex - 3 : Green
    Color vertex - 4 : Red
    Color vertex - 5 : Red    
Explanation 2:

 So as mentioned in the problem heirarchy starts from vertex numbered 1.
 So (2-ancestor) of vertex 3 is vertex 1 and (1-ancestor) of vertex 2 is 1.
*/