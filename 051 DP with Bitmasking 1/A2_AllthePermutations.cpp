/*

All the permutations
Problem Description

You are given two integer array A and B of size N.
You are allowed to shuffle array A such that sum of "A[i] xor B[i]" for all i in [1, N] is minimized.



Problem Constraints
1 <= N <= 16
0 <= A[i],B[i] <= 10^8


Input Format
First argument of input contains a integer array A. Second argument of input contains a integer array B.


Output Format
Return a single integer denoting the minimized sum.


Example Input
Input 1:
    A = [1, 2], B = [2, 3]
Input 2:

    A = [1, 0, 3], B = [5, 3, 4]


Example Output
Output 1:
2
Output 1:

8


Example Explanation
Explanation 1:
if A = [1, 2] then ( 1 ^ 2 ) + ( 2 ^ 3 ) = 4
if A = [2, 1] then ( 2 ^ 2 ) + ( 1 ^ 3 ) = 2
clearly, second option is better.

*/

#include <bits/stdc++.h>
using namespace std;
// Using Barn Karninghan's algorithm
int countBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        cnt++;
    }

    return cnt;
}

int dp[(1 << 16)];
int n, A[16], B[16];

int solve1(int mask = 0)
{
    int idx = countBits(mask);

    if (idx == n)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if ((mask >> i) & 1)
            continue;
        ans = min(ans, (A[idx] ^ B[i]) + solve1(mask | (1 << i)));
    }
    dp[mask] = ans;

    return ans;
}

int solve(vector<int> &Arr, vector<int> &Brr)
{

    memset(dp, -1, sizeof(dp));
    n = Arr.size();

    for (int i = 0; i < n; ++i)
    {
        A[i] = Arr[i];
        B[i] = Brr[i];
    }

    return solve1();
}

int main()
{

    vector<int> A{1, 0, 3}, B{5, 3, 4};

    cout << "Ans is " << solve(A, B) << endl;

    return 0;
}