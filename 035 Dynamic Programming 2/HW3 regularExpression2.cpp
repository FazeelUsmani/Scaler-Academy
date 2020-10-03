/*

Regular Expression II
Problem Description

Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.

' . ' : Matches any single character.
' * ' : Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Problem Constraints
1 <= length(A), length(B) <= 104



Input Format
The first argument of input contains a string A.
The second argument of input contains a string B denoting the pattern.



Output Format
Return 1 if the patterns match else return 0.



Example Input
Input 1:

 A = "aab"
 B = "c*a*b"
Input 2:

 A = "acz"
 B = "a.a"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 'c' can be repeated 0 times, 'a' can be repeated 1 time. Therefore, it matches "aab".
 So, return 1.
Explanation 2:

 '.' matches any single character. First two character in string A will be match. 
 But the last character i.e 'z' != 'a'. Return 0.

*/

bool _isMatch(const string &str, int s, const string &pat, int p){
    if(p == pat.length())        return s == str.size();

    bool star = p < pat.size()-1 and pat[p + 1] == '*';
    bool match = s < str.size() and  (pat[p] == '.' or str[s] == pat[p]);
    // if theres kleene
    if(star){
        // dont match rec, match rec.
        return _isMatch(str, s, pat, p+2) 
            or ( match and _isMatch(str, s+1, pat, p));
    }
    return match and _isMatch(str, s+1, pat, p+1);
}


int Solution::isMatch(const string str, const string pat) {
    return _isMatch(str, 0, pat, 0);
}
