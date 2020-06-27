/*


Permutations

Problem Description

You are given two strings A and B of size N and M respectively.

You have to find the count of all permutations of A present in B as a substring. You can assume a string will have only lowercase letters.



Problem Constraints
1 <= N < M <= 105



Input Format
Given two argument, A and B of type String.



Output Format
Return a single Integer, i.e number of permutations of A present in B as a substring.



Example Input
Input 1:

 A = "abc"
 B = "abcbacabc"
Input 2:

 A = "aca"
 B = "acaa"


Example Output
Output 1:

 5
Output 2:

 2


Example Explanation
Explanation 1:

 Permutations of A that are present in B as substring are:
    1. abc
    2. cba
    3. bac
    4. cab
    5. abc
    So ans is 5.
Explanation 2:

 Permutations of A that are present in B as substring are:
    1. aca
    2. caa 

*/


bool matches (int A[], int B[]){
    for (int i = 0; i < 256; ++i){
        if (A[i] != B[i]){
            return false;
        }
    }
            
    return true;
}

int Solution::solve(string A, string B) {
    
    int len1 = A.size(), len2 = B.size();
    if (len1 > len2)
        return 0;
        
    int mapA[256] = {0}, mapB[256] = {0};
    int cnt = 0;
    
    for (int i = 0; i < len1; ++i){
        mapA[A[i]]++;
        mapB[B[i]]++;
    }
    
    for (int i = len1; i < len2; ++i){
        if (matches(mapA, mapB) == true){
            ++cnt;
        }
        mapB[B[i-len1]]--;
        mapB[B[i]]++;
    }
    
    if (matches(mapA, mapB) == true)
        cnt++;
        
    return cnt;
}
