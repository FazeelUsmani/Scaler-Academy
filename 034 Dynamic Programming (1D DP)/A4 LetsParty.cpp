/*
Let's Party
Problem Description

In Danceland, one person can party either alone or can pair up with another person.

Can you find in how many ways they can party if there are A people in Danceland?

Note: Return your answer modulo 10003, as the answer can be large.



Problem Constraints
1 <= A <= 105



Input Format
Given only argument A of type Integer, number of people in Danceland.



Output Format
Return an integer denoting the number of ways people of Danceland can party.



Example Input
Input 1:

 A = 3
Input 2:

 A = 5


Example Output
Output 1:

 4
Output 2:

 26


Example Explanation
Explanation 1:

 Let suppose three people are A, B, and C. There are only 4 ways to party
 (A, B, C) All party alone
 (AB, C) A and B party together and C party alone
 (AB, C) A and B party together and C party alone
 (BC, A) B and C party together and A
 here 4 % 10003 = 4, so answer is 4.
 
Explanation 2:

 Number of ways they can party are: 26.

*/

int Solution::solve(int n) {
    
    if (n == 1)
        return 1;
        
    int ways[n+1] {1};
    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n; i++)
        ways[i] = (ways[i-1] + (i-1)*ways[i-2]) % 10003;

    /*
    ways[i-1] --> for the ith person wants to dance alone
    (i-1)*ways[i-2] --> for the ith person wants to pair with someone
    */

    return ways[n]%10003;
}
