/*
Reconstruct links!
Problem Description

A country named Mirage has a total of N cities connected via N - 1 links.

Each link connects a pair of cities (u, v) and also has a weight w assigned to it where w denotes the distance between city u and v.

Distance between any two cities (u ,v) is denoted as D(u, v) where D(u, v) is sum of weights of each link which occurs on a simple path from city u to v.

You have to answer Q queries, in each query you are given with three integer (ui, vi, wi), you have to check whether you can reduce D(ui, vi) by changing the weight of any one link to wi on the simple path from city ui to vi.

If D(u, v) is reduced then return 1 for that query else return 0.

NOTE:

Each query is independent i.e for each query consider the given tree to answer it.
Cities are labelled from 1 to N.
It is guaranteed that there is only one simple path from any city u to any v.


Problem Constraints
2 <= N <= 105

1 <= Q <= 105

1 <= weight of any link, wi in any query <= 109

For each query 1 <= (ui != vi) <= N



Input Format
First argument is an 2D integer array A of size (N - 1) x 3 where (A[i][0], A[i][1], A[i][2]) denotes an bidirectional link between city A[i][0] and city A[i][1] with distance A[i][2] between them.

Second argument is an 2D integer array B of size Q x 3 where (B[i][0], B[i][1], B[i][2]) denotes (ui, vi, wi) for the ith query.



Output Format
Return an integer array containing Q integers denoting the answers to queries.

NOTE:

Return the answers to the queries in the order, in which the queries occur in the input.


Example Input
Input 1:

 A = [  [1, 2, 5],
        [1, 3, 4],
        [2, 4, 10],
        [2, 5, 8],
        [3, 6, 2],
        [3, 7, 11]
     ]
 B = [  [2, 5, 11],
        [2, 3, 3]
     ]
Input 2:

 A = [  [1, 2, 5]
     ]
 B = [  [1, 2, 5]
     ]


Example Output
Output 1:

 [0, 1]
Output 2:

 [0]


Example Explanation
Explanation 1:

 Query 1: D(2, 5) is 8 initially so not necessary to update it to 11 so we will return 0.
 Query 2: D(2, 3) is 9 initially if we change the weight of edge (1, 2) to 3 then new D(2, 3) will be 7 so we will return 1.
Explanation 2:

 Query 1: D(1, 2) is 5 initially if we change the weight of edge (1, 2) to 5 then new D(1, 2) will be 5 so D(1, 2)
 didn't get reduced so we will return 0.


*/