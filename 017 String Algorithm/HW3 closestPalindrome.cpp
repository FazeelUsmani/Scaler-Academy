/*

Closest Palindrome
Problem Description

Groot has a profound love for palindrome which is why he keeps fooling around with strings.
A palindrome string is one that reads the same backward as well as forward.

Given a string A of size N consisting of lowercase alphabets, he wants to know if it is possible to make the given string a palindrome by changing exactly one of its character.



Problem Constraints
1 <= N <= 105



Input Format
First and only argument is a string A.



Output Format
Return the string YES if it is possible to make the given string a palindrome by changing exactly 1 character. Else, it should return the string NO.



Example Input
Input 1:

 A = "abbba"
Input 2:

 A = "adaddb"


Example Output
Output 1:

 "YES"
Output 2:

 "NO"


Example Explanation
Explanation 1:

 We can change the character at index 3(1-based) to any other character. The string will be palindromic.
Explanation 2:

 To make the string palindromic we need to change 2 characters. 

*/


bool checkPalindrome (string S) {
    
    int n = S.size();
    bool flag = true;
    for (int i = 0; i < n/2; ++i) {
        if (S[i] != S[n-i-1]) {
            flag = false;
        }
    }
    return flag;
}

string Solution::solve(string A) {
    
    int n = A.size();
    if (n == 1)
        return "YES";
    
    if (checkPalindrome(A)) {
        if (n&1) {
            return "YES";
        }
        else {
            return "NO";
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n/2; ++i) {
        if (A[i] != A[n-i-1]) {
            cnt++;
        }
    }
    
    if (cnt <= 1) {
        return "YES";
    }
    else {
        return "NO";
    }
}
