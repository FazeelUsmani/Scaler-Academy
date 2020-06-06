/*

Stairs

Problem Description

You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Problem Constraints
1 <= A <= 36



Input Format
The first and the only argument contains an integer A, the number of steps.



Output Format
Return an integer, representing the number of ways to reach the top.



Example Input
Input 1:

 A = 2
Input 2:

 A = 3


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

 Distinct ways to reach top: [1, 1], [2].
Explanation 2:

 Distinct ways to reach top: [1 1 1], [1 2], [2 1].

*/

int Solution::climbStairs(int n) {
    
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
        
    int ans = 0, prev1 = 1, prev2 = 1;
    
    for (int i = 2; i <= n; ++i){
        ans = prev1 + prev2;
        prev2 = prev1;
        prev1 = ans;
    }
    
    return ans;
}
