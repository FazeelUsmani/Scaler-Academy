// https://www.geeksforgeeks.org/noble-integers-in-an-array-count-of-greater-elements-is-equal-to-value

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A{-5, -2, -3, 0, -6, 8, -10, -6, -8, -1, 6, -9, 0, -6, 2, 2, 2, 0, -5, -5, -8, 9, -10, -8, 8, 3, 8, 0, -6, 0, -1, -9, 9, 6, 2, 5, 4, -6, 9, -1, 3, 6, 0, 5, -10, -8, 9, -6, 3, -5, -9, -3, -6, 3, -9, 4, -4, 9, -6, -8, -8, -4, -6, -9, -8, -2, -2, -1} sort(A.begin(), A.end());
    sort(A.begin(), A.end());
    int ans = -1;

    for (int i = 0; i < A.size() - 1; ++i)
    {
        if (A[i] == A[i + ])
            continue;
        if (A[i] == n - i - 1)
        {
            ans = 1;
            break;
        }
    }
    cout(ans);

    return 0;
}
