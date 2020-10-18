#include <bits/stdc++.h>
using namespace std;

// This solution is accepted on test but WA on submission

int check(string A, string B)
{
    int n = A.size();
    if (n != B.size())
        return false;

    int index;
    for (int i = 0; i < n; ++i)
    {
        if (B[i] == A[0])
        {
            index = i;
        }
    }
    int temp = index;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] != B[index])
        {
            return -1;
        }
        index = (index + 1) % n;
    }

    return temp;
}

int Solution::solve(int A, vector<string> &B)
{

    int ans = INT_MAX;
    int n = B.size();
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            int x = check(B[i], B[j]);
            int y = check(B[j], B[i]);
            if (x == -1 && y == -1)
            {
                return -1;
            }
            else if (x == -1)
            {
                cnt += y;
            }
            else if (y == -1)
            {
                cnt += x;
            }
            else
            {
                cnt += min(x, y);
            }
        }
        ans = min(ans, cnt);
    }

    return ans;
}

int main()
{
    // vector<string> A{"thanos", "hanost", "nostha"};
    // vector<string> B{"thanos", "htanos"};
    // vector<string> C{"xzzwo", "zwoxz", "zzwox", "xzzwo"};
    vector<string> D{"abcabc", "cabcab"};

    cout << "Ans is";
    cout << solve(2, D) << endl;

    return 0;
}