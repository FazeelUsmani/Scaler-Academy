/*

Ways to Decode
Problem Description

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message denoted by string A containing digits, determine the total number of ways to decode it.



Problem Constraints
1 <= length(A) <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return an integer, representing the number of ways to decode the string.



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

#include<bits/stdc++.h>
using namespace std;




int way(string A, int i){
    
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

int numDecodings(string A) {
    
    return way(A, 0);
}


// Optimized using DP
int numDecodings2(string A) {
    
    int n = A.size();
    
    if (A[0] == '0')
        return 0;
    
    int ways[n+1] = {0};
    ways[0] = 1;
    ways[1] = 1;
    
    for (int i = 2; i <= n; ++i){
        
        if (A[i-1] >= '1' && A[i-1] <= '9')
            ways[i] = (ways[i] + ways[i-1]) % 1000000007;
        
        if (A[i-2] == '1')
            ways[i] = (ways[i] + ways[i-2]) % 1000000007;
        else if (A[i-2] == '2' && A[i-1] >= '0' && A[i-1] <= '6')
            ways[i] = (ways[i] + ways[i-2]) % 1000000007;
    }

    for (int &x: ways)
        cout<<x<<" ";
    cout<<endl;
    
    return ways[n]%1000000007;
}



int main(){
    string A = "875361268549483279131";
    cout<<"Ans is "<<numDecodings(A)<<endl;
    cout<<"DP SOlution "<<numDecodings2(A);

    return 0;
}



//  int n = A.length();
    
//     if (n == 0)
//         return 0;
        
//     if (A[0] == '0') 
//         return 0;
        
//     int ans[n+1];
//     ans[0] = 1;
//     ans[1] = A[0] == '0' ? 0 : 1;
    
//     for (int i = 2; i <= n; i++){
        
//         ans[i] = 0;
//         if (A[i-1] >= '1')
//             ans[i] += ans[i-1];
//         if (A[i-2] == '1' || (A[i-2] == '2' && A[i-1] >= '1' && A[i-1] <= '6'))
//             ans[i] += ans[i-2];