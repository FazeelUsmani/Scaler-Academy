/*

Obsessive String
Problem Description

Given two string A and B consisting of lowercase english letters.
You need to find how many ways are there to extract k (>=1) non-overlapping substrings from A such that each of them contains string B as a substring.

More formally, you need to calculate the number of ways to choose two sequences x1, x2, ..., xk and y1, y2, ..., yk satisfying the following requirements:

1 <= xi, yi <= |A| where (1 <= i <= k)
yi >= xi
xi+1 > yi
string B is the substring of Axi Axi+1 ... Ayi (string A is considered as 1-indexed).
As the number of ways can be rather large print it modulo 109+7.



Problem Constraints
1 <= |A| <= 100000

1 <= |B| <= 100000



Input Format
The first argument is string A.
The second argument is string B.



Output Format
Return number of ways to extract k (>=1) non-overlapping substrings from A such that each of them contains string B as a substring modulo (109+7).



Example Input
Input 1:

 A = "bcbcb" 
 B = "bc"
Input 2:

 A = "bbbc"
 B = "bbbc"


Example Output
Output 1:

 10
Output 2:

 1


Example Explanation
Explanation 1:

 Following are the 10 ways:
    ["bc"]
    ["bcb"]
    ["bcbc"]
    ["bcbcb"]
    ["cbc"]
    ["cbcb"]
    ["bc"]
    ["bcb"]
    ["bc", "bc"]
    ["bc", "bcb"]
Explanation 2:

 The only substring is "bbbc".

*/
