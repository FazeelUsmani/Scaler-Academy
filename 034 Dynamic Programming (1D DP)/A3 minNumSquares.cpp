/*

Minimum Number of Squares
Problem Description

Given an integer A. Return minimum count of numbers, sum of whose squares is equal to A.



Problem Constraints
1 <= A <= 105



Input Format
First and only argument is an inetegr A.



Output Format
Return an integer denoting the minimum count.



Example Input
Input 1:

 A = 6
Input 2:

 A = 5


Example Output
Output 1:

 3
Output 2:

 2


Example Explanation
Explanation 1:

 Possible combinations are : (12 + 12 + 12 + 12 + 12 + 12) and (12 + 12 + 22).
 Minimum count of numbers, sum of whose squares is 6 is 3. 
Explanation 2:

 We can represent 5 using only 2 numbers i.e. 12 + 22 = 5
*/

int Solution::countMinSquares(int A) {
    
    int ans[A+1] = {0};
    ans[1] = 1;
    
    for (int i = 2; i <= A; i++){
        ans[i] = i;
        for (int j = 1; j*j <= i; j++){
            ans[i] = min(ans[i], 1 + ans[i- j*j]);
        }
    }
    
    return ans[A];
}
