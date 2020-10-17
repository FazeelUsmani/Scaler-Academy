/*

Scramble String
Problem Description

Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings A and B of the same length, determine if B is a scrambled string of S.



Problem Constraints
1 <= len(A), len(B) <= 50



Input Format
The first argument of input contains a string A.

The second argument of input contains a string B.



Output Format
Return 1 if true, 0 if false



Example Input
Input 1:

 A = "we"
 B = "we"
Input 2:

 A = "phqtrnilf"
 B = "ilthnqrpf"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 
It is the same string.


Explanation 2:

 There is no way to achieve B from A.

*/


int Solution::isScramble(const string s1, const string s2) {
    int len = s1.size();
    bool dp[len + 1][len + 1][len + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = len - 1; i >= 0; i--) {
        for (int j = len - 1; j >= 0; j--) {
            dp[i][j][1] = (s1[i] == s2[j]);
            for (int l = 2; i + l <= len && j + l <= len; l++) {
                for (int n = 1; n < l; n++) {
                    dp[i][j][l] |= dp[i][j][n] && dp[i + n][j + n][l - n];
                    dp[i][j][l] |= dp[i][j + l - n][n] && dp[i + n][j][l - n];
                }
            }
        }
    }
    return dp[0][0][len];
}
