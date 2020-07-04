/*

Ways to Decode
Problem Description

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message denoted by string A containing digits, determine the total number of ways to decode it modulo 109 + 7.

.



Problem Constraints
1 <= length(A) <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return an integer, representing the number of ways to decode the string modulo 109 + 7..



Example Input
Input 1:

 A = "12"
Input 2:

 A = "8"


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:

 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.


*/


int way(string& A, int i){
    
    if(i == A.size())
        return 1;
        
    else if(A[i] == '0')
        return 0;
        
    else if(A[i] > '2')
        return way(A,i+1);
        
    else if(i+1 >= A.size())
        return way(A,i+1);
        
    else if(A[i] == '1' || (A[i] == '2' && A[i+1] < '7'))
        return way(A,i+1) +  way(A,i+2);
        
    else
        return way(A,i+1);
}

int Solution::numDecodings(string A) {
    
    return way(A, 0);
}
