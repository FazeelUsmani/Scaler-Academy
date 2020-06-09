/*

Longest Balanced Substring

Problem Description

Given a string A made up of multiple brackets of type "[]" , "()" and "{}" 
find the length of the longest substring which forms a balanced string .

Conditions for a string to be balanced :

Blank string is balanced ( However blank string will not be provided as a test case ).
If B is balanced : (B) , [B] and {B} are also balanced.
If B1 and B2 are balanced then B1B2 i.e the string formed by concatenating B1 and B2 is also balanced.


Problem Constraints
0 <= |A| <= 106



Input Format
First and only argument is an string A.



Output Format
Return an single integer denoting the lenght of the longest balanced substring.



Example Input
Input 1:

 A = "[()]"
Input 2:

 A = "[(])"


Example Output
Output 1:

 4
Output 2:

 0


Example Explanation
Explanation 1:

 Substring [1:4] i.e "[()]" is the longest balanced substring of length 4.
Explanation 2:

 None of the substring is balanced so answer is 0.



*/


int Solution::LBSlength(const string A) {
    
    int n = A.length();
    
    if (n < 2)
        return 0;
    
    vector<int> longest (n, 0);
    int ans = 0;
    
    for (int i = 1; i < n; i++){
        
        if (A[i] == ')' || A[i] == ']' || A[i] == '}'){
            
            if ( (A[i] == ']' && A[i-1] == '[') || 
                 (A[i] == '}' && A[i-1] == '{') || 
                 (A[i] == ')' && A[i-1] == '(') ){
                    
                    longest[i] = longest[i-2] + 2;
                    ans = max(ans, longest[i]);
                    
            }
            
            else{
                
                if ( ((i-longest[i-1]-1) >= 0) && 
                    ( (A[i] == ']' && A[i-longest[i-1]-1] == '[') ||
                      (A[i] == '}' && A[i-longest[i-1]-1] == '{') || 
                      (A[i] == ')' && A[i-longest[i-1]-1] == '(') ) ){
                    
                        longest[i] = longest[i-1] + 2 + ( (i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                        ans = max(ans, longest[i]);
                }
            }
        }
    }
    
    return ans;
}
