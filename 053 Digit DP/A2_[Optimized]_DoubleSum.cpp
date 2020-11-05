#include <bits/stdc++.h>
using namespace std;

#define ll long long
long long MOD = 1000000007;
vector<pair<ll, ll>> dp;

// array - 10^5
// vector - 10^6

void doubleSum(long long sum, int len, long long val)
{
    if (len > 15)
        return;

    sum %= MOD;
    val %= MOD;

    dp.push_back(make_pair(val, sum));

    if (val == 0)
    {
        for (int i = 1; i <= 9; ++i)
        {
            doubleSum(sum + i, len + 1, i);
        }
        return;
    }
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            if (i == 0)
            {
                doubleSum(sum, len + 1, val * 10);
            }
            else
            {
                doubleSum(sum + i, len + 1, (val * 10) + i);
            }
        }
        return;
    }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{

    return a.first < b.first;
}

int main()
{
    vector<string> A{"10", "15"};

    if (dp.empty())
    {
        doubleSum(0, 0, 0);

        sort(dp.begin(), dp.end(), cmp);
    }

    for (int i = 0; i < A.size(); i = i + 2)
    {
        int left = 0;
        for (char x : A[i])
        {
            left = (left * 10) + (x - '0');
        }

        int right = 0;
        for (char x : A[i + 1])
        {
            right = (right * 10) + (x - '0');
        }
    }

    return 0;
}