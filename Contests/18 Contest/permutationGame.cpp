#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int solve(vector<int> &A)
{

    sort(A.begin(), A.end());

    int ans = 0;
    int curr = 1;
    for (int i = 0; i < A.size(); ++i)
    {
        if (curr < A[i])
        {
            ans += abs(curr - A[i]);
        }
        else
        {
            ans += abs(A[i] - curr);
        }
        curr++;
        ans %= MOD;
    }

    return ans;
}

int main()
{
    vector<int> A{-1, -1, 3};
    cout << solve(A);

    return 0;
}