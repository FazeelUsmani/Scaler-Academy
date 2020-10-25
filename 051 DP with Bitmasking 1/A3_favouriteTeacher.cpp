/*

Favourite Teacher
Problem Description

There are N teachers and N students both numbered from 1 to N. We know that each student has a preference for teachers. We have a matrix A. A[i][j] is 1 if ith student likes teacher j. It is zero otherwise.

We want to find the number of ways to assign a teacher to each student so that each student only gets one of his preferred teachers and each teacher is allowed to only one student. Since the answer can be large return it modulo 109 + 7.



Problem Constraints
1 <= N <= 20

0 <= A[i][j] <= 1



Input Format
First line contains a 2-D matrix A of size NxN.



Output Format
Return the number of ways to allot teachers to students.



Example Input
Input 1:

  A = [
       [0, 1, 1]
       [1, 0, 1]
       [1, 1, 1]
      ]
Input 2:

  A = [
       [0]
      ]


Example Output
Output 1:

  3
Output 2:

  0


Example Explanation
Explanation 1:

  There are 3 ways to form pairs (i,j) denotes pair of i-th student and j-th teacher.
  (1,2), (2,1), (3,3)
  (1,2), (2,3), (3,1)
  (1,3), (2,1), (3,2)
Explanation 2:

  We can't form a pair.

*/

#include <bits/stdc++.h>
using namespace std;

/*     WA on submission | Passing some test cases
int dp[20][1<<20];

int solve1(vector<vector<int> > &A, int row, int mask) {
    if (row == A.size())
        return 1;
    if (dp[row][mask] != -1)
        return dp[row][mask];
    int ans = 0;
    for (int col = 0; col < A.size(); ++col) {
        if ( ( (mask >> col) & 1) || (A[row][col] == 0) )
            continue;
        ans += solve1(A, row+1, mask | (1<<col));
    }
    
    return dp[row][mask] = ans;
}


int Solution::solve(vector<vector<int> > &A) {
    
    memset(dp, -1, sizeof(dp));
    
    return solve1(A, 0, 0);
}
*/

int dp[1 << 20];
int ArrSize, A[20][20];

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

int solve1(int mask)
{
    int row = countBits(mask);
    if (row == ArrSize)
        return 1;
    if (dp[mask] != -1)
        return dp[mask];
    long long ans = 0;
    for (int col = 0; col < ArrSize; ++col)
    {
        if (((mask >> col) & 1) || (A[row][col] == 0))
            continue;
        ans = (ans + solve1(mask | (1 << col))) % 1000000007;
    }
    dp[mask] = ans;

    return ans;
}

int solve(vector<vector<int>> &Arr)
{
    memset(dp, -1, sizeof(dp));
    ArrSize = Arr.size();

    for (int i = 0; i < Arr.size(); ++i)
    {
        for (int j = 0; j < Arr[i].size(); ++j)
        {
            A[i][j] = Arr[i][j];
        }
    }

    return solve1(0);
}

int main()
{
    vector<vector<int>> A{{0, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    cout << "Ans is " << solve(A) << endl;

    return 0;
}