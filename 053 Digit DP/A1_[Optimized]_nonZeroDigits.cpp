#include <bits/stdc++.h>
using namespace std;

int N;
string v;
vector<long long> dp;

void count1(long long nonZero, int len, long long val)
{

    if ((len > 18) || (nonZero > 3))
    {
        return;
    }

    dp.push_back(val);

    if (val == 0)
    {
        for (int i = 1; i <= 9; ++i)
        {
            count1(1, 1, i);
        }
        return;
    }
    else
    {
        for (int i = 0; i <= 9; ++i)
        {
            if (i == 0)
            {
                count1(nonZero, len + 1, val * 10);
            }
            else
            {
                count1(nonZero + 1, len + 1, val * 10 + i);
            }
        }
        return;
    }
}

vector<int> solve(vector<string> &A)
{
    vector<int> result;
    int currAns;

    if (dp.empty())
    {
        count1(0, 0, 0);
        sort(dp.begin(), dp.end());
    }

    for (int i = 0; i < A.size(); i += 2)
    {
        long long left = 0;
        for (char x : A[i])
        {
            left = left * 10 + x - '0';
        }

        long long right = 0;
        for (char x : A[i + 1])
        {
            right = right * 10 + x - '0';
        }

        auto it = upper_bound(dp.begin(), dp.end(), right);
        auto it1 = lower_bound(dp.begin(), dp.end(), left);

        result.push_back(it - it1);
    }

    return result;
}

int main()
{
    dp.clear();
    vector<string> A{"11111", "22222"};
    vector<int> ans = solve(A);

    for (int x : ans)
        cout << x << " ";

    return 0;
}