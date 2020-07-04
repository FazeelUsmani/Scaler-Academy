/*

Distinct Subsequences
Problem Description

Given two sequences A and B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).



Problem Constraints
1 <= length(A), length(B) <= 700



Input Format
The first argument of input contains a string A.
The second argument of input contains a string B.



Output Format
Return an integer representing the answer as described in the problem statement.



Example Input
Input 1:

 A = "abc"
 B = "abc"
Input 2:

 A = "rabbbit" 
 B = "rabbit" 


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

 Both the strings are equal.
Explanation 2:

 These are the possible removals of characters:
    => A = "ra_bbit" 
    => A = "rab_bit" 
    => A = "rabb_it"

 Note: "_" marks the removed character.


*/

int Solution::numDistinct(string s, string t) {
    
    int n = s.length(), m = t.length();
    if (m > n)
        return 0;
        
    int distictSub[m+1][n+1];
    for (int i = 1; i <= m; ++i)
        distictSub[i][0] = 0;
        
    for (int j = 0; j <= n; j++) 
        distictSub[0][j] = 1; 
  
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
  
            if (t[i - 1] != s[j - 1]) 
                distictSub[i][j] = distictSub[i][j - 1]; 
  
            else
                distictSub[i][j] = distictSub[i][j - 1] + distictSub[i - 1][j - 1]; 
        } 
    } 
  
    
    return distictSub[m][n]; 
}

