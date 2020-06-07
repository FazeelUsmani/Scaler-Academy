/*

Longest Common Subsequence

Problem Description

Given two strings A and B. Find the longest common subsequence ( A sequence which does not need to be contiguous), 
which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= Length of A, B <= 1005



Input Format
First argument is a string A.
Second argument is a string B.



Output Format
Return an integer denoting the length of the longest common subsequence.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"
Input 2:

 A = "aaaaaa"
 B = "ababab"


Example Output
Output 1:

 5
Output 2:

 3


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5.
Explanation 2:

 The longest common subsequence is "aaa", which has a length of 3.


*/


int Solution::solve(string s1, string s2) {
    
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1];

    // first row as 0, because any char with " " matches 0 length
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    // first col as 0, because any char with " " matches 0 length
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];  // taking diagonal value
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);  // taking max of left and top cell
            }
            
        }
    }

    
 
    return dp[m][n];
}

