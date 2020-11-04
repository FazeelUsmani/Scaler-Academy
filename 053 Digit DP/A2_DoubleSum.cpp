#include <bits/stdc++.h>
using namespace std;

unsigned long long int dp[9 * 16][16][2];

int digitdp(int pos, int flag, string v, int n, int sum);

vector<int> Solution::solve(vector<string> &A)
{

    vector<int> sol;

    for (int i = 0; i < A.size(); i += 2)
    {

        memset(dp, -1, sizeof dp);
        int l = digitdp(0, 1, A[i], A[i].size(), 0);
        memset(dp, -1, sizeof dp);
        int r = digitdp(0, 1, A[i + 1], A[i + 1].size(), 0);
        usigned int ans = r - l;

        if (ans < 0)
            ans += 1000000007;

        for (int k = 0; k < A[i].size(); k++)
            ans += A[i][k] - '0';
        sol.push_back(ans % 1000000007)
    }
    return sol;
}

int digitdp(int pos, int flag, string v, int n, int sum)
{
    if (dp[sum][pos][flag] != -1)
        return dp[sum][pos][flag] % 1000000007;
    if (pos == n)
        return sum;
    int limit = 9;
    if (flag == 1)
        limit = (v[pos] - '0');
    unsigned long long int z = 0;
    for (int i = 0; i < limit; i++)
    {
        z = z + (unsigned long long int)digitdp(pos + 1, 0, v, n, sum + i);
        z = z % 1000000007;
    }

    if (flag == 1)
    {
        z = z + (unsigned long long int)digitdp(pos + 1, 1, v, n, sum + limit);
        z = z % 1000000007;
    }
    else
    {
        z = z + (unsigned long long int)digitdp(pos + 1, 0, v, n, sum + limit);
        z = z % 1000000007;
    }

    return dp[sum][pos][flag] = z;
}

int main()
{

    return 0;
}