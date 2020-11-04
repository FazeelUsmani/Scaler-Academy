#include <bits/stdc++.h>
using namespace std;

int solve(int N, vector<int> &B)
{

    sort(B.begin(), B.end());
    int cntB = 0, cntW = 0;
    for (int x : B)
    {
        if (x & 1)
        {
            cntB++;
        }
        else
        {
            cntW++;
        }
    }

    int curr = N - 1;
    int ans1 = 0;

    for (int i = B.size() - 1; i >= 0; i--)
    {
        ans1 += abs(curr - B[i]);
        curr = curr - 2;
    }

    curr = N;
    int ans2 = 0;
    for (int i = B.size() - 1; i >= 0; i--)
    {
        ans2 += abs(curr - B[i]);
        curr = curr - 2;
    }

    return min(ans1, ans2);
}

int main()
{
    int A = 100;
    vector<int> B{
        93,
        54,
        57,
        61,
        68,
        66,
        70,
        96,
        64,
        82,
        80,
        75,
        69,
        77,
        76,
        94,
        67,
        86,
        90,
    };
    cout << solve(A, B);

    return 0;
}