/*
Regular Expression Match

Problem Description

Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.

' ? ' : Matches any single character.
' * ' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Problem Constraints
1 <= length(A), length(B) <= 104



Input Format
The first argument of input contains a string A.
The second argument of input contains a string B.



Output Format
Return 1 if the patterns match else return 0.
/*




Example Input
Input 1:

 A = "aaa"
 B = "a*"
Input 2:

 A = "acz"
 B = "a?a"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Since '*' matches any sequence of characters. Last two 'a' in string A will be match by '*'.
 So, the pattern matches we return 1.
Explanation 2:

 '?' matches any single character. First two character in string A will be match. 
 But the last character i.e 'z' != 'a'. Return 0.
 */
 
 int Solution::isMatch(const string s, const string p) {
    
    int n=s.size(),m=p.size();
    int star=-1,prev_start=0;
    int i=0,j=0;
    
    for(;i<n;){
        
        if(s[i]==p[j] || p[j]=='?'){
            i++,j++;
        }
        
        else if(p[j]=='*'){
            star = j++;
            prev_start = i;
        }
        
        else if(star != -1){
            j = star;
            i = ++prev_start;
        }
        
        else{
            return false;
        }
    }
    
    while(j<m && p[j]=='*')
        j++;
    
    return (j==m);
}

 
