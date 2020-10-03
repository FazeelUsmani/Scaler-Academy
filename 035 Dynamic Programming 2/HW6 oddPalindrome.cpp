/*

Odd Palindrome
Problem Description

A palindrome string is a string which reads the same forward and backward. If a palindrome string is of odd length l, then (l+1)/2th character (1 index based) is said to be the centre of the palindrome.

You are given a string A. Return an array X of integers where X[i] = (number of odd length palindrome subsequence of A with A[i] as the centre) modulo (109 + 7).

A subsequence of A is a string which can be derived from A by deleting some of its character.



Problem Constraints
1 <= length(A) <= 1000
Every character of A will be a lowercase English letter 'a' - 'z'.



Input Format
First and only argument is a string A.



Output Format
Return an integer array X as mentioned in the question.



Example Input
Input 1:

 A = "xyzx"
Input 2:

 A = "ababzz"


Example Output
Output 1:

 [1, 2, 2, 1]
Output 2:

 [1, 2, 2, 1, 1, 1]


Example Explanation
Explanation 1:

 
 Index(i)  |   Palindrome subsequences with centre i
   0       |   a        
   1       |   y, xyx
   2       |   z, xzx
   3       |   x
 So, output array is [1, 2, 2, 1]

Explanation 2:

 Index(i)  |  Palindrome subsequences with centre i
   0       |  a    
   1       |  b, aba
   2       |  a, bab
   3       |  b
   4       |  z
   5       |  z
 So, output array is [1, 2, 2, 1, 1, 1]  
 

*/


vector<int> Solution::solve(string s) {
    
  const int mod = 1e9 + 7;
  const int n = s.size();

  // what dp[i][j] stores ?
  // it stores the count of all even length palindromes whose first half characters are from 
  // prefix of length i and second half characters are from suffix of length j
  // for eg. for string "adxcdaa", dp[2][4] = 5 (2 for "adda" + 1 for "dd" + 2 for "aa")
  
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); 

  for (int prefLen = 1; prefLen <= n; prefLen++)
  {
    for (int suffLen = 1; suffLen <= n && prefLen + suffLen <= n; suffLen++)
    {
      int temp = ((dp[prefLen - 1][suffLen] + dp[prefLen][suffLen - 1]) % mod - dp[prefLen -1][suffLen - 1] + mod) % mod;
      dp[prefLen][suffLen] = (dp[prefLen][suffLen] + temp) % mod;

      const auto lastPrefChar = s[prefLen - 1];
      const auto firstSuffChar = s[n - suffLen];

      if(lastPrefChar == firstSuffChar)
      {
        int temp = 1 + // palindrom consisting of just lastPrefChar and firstSuffChar.
                   dp[prefLen -1][suffLen - 1]; // already calculated palindromes
        dp[prefLen][suffLen] = (dp[prefLen][suffLen]  + temp) % mod;
      }
    }
  }

  // Now that we have dp, we can calculate ans for each of the n positions.
  vector<int> ans;
  for (int prefLen = 0; prefLen < n; prefLen++)
  {
    const int suffLen = n - 1 - prefLen;
    ans.push_back(1 + // odd palindrom of length 1 by choosing just centre.
                   dp[prefLen][suffLen] // All other palindromes centred around current pos.
                 );
  }
    
  return ans;
}
