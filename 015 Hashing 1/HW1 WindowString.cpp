/*
Window String
Problem Description

Given a string A and a string B, find the window with minimum length in A which will contain all the characters in B in linear time complexity.
Note that when the count of a character c in B is x, then the count of c in minimum window in A should be at least x.

Note:

If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index )


Problem Constraints
1 <= size(A), size(B) <= 106



Input Format
First argument is a string A.
Second argument is a string B.



Output Format
Return a string denoting the minimum window.



Example Input
Input 1:

 A = "ADOBECODEBANC"
 B = "ABC"
Input 2:

 A = "Aa91b"
 B = "ab"


Example Output
Output 1:

 "BANC"
Output 2:

 "a91b"


Example Explanation
Explanation 1:

 "BANC" is a substring of A which contains all characters of B.
Explanation 2:

 "a91b" is the substring of A which contains all characters of B.


*/

string Solution::minWindow(string str, string pat) {
    
    const int MAX_CHAR = 256;
    int len1 = str.size(), len2 = pat.size();
    
    if (len1 < len2)
        return "";
    
    int hashStr[MAX_CHAR] = {0};
    int hashPat[MAX_CHAR] = {0};
    
    for (int i = 0; i < len2; ++i)
        hashPat[ pat[i] ]++;
        
    int start = 0, startIndex = -1, cnt = 0, minLength = INT_MAX;
    
    for (int i = 0; i < len1; ++i){
        hashStr[str[i]]++;
        
        if (hashPat[str[i]] != 0 && hashStr[str[i]] <= hashPat[str[i]])
            cnt++;
            
        if (cnt == len2){
    
            while (hashStr[str[start]] > hashPat[str[start]] || hashPat[str[start]] == 0){
                hashStr[str[start]]--;
                start++;
            }
            
            int currLen = i - start + 1;
            if (currLen < minLength){
                minLength = currLen;
                startIndex = start;
            }
        }
    }
    
    if (startIndex == -1)
        return "";
        
    return str.substr(startIndex, minLength);
}
