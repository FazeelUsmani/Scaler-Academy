#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &A)
{

    int m = A.size();
    int n = A[m - 1].size();

    for (int i = m - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (A[i + 1][j] < A[i + 1][j + 1])
            {
                A[i][j] += A[i + 1][j];
            }
            else
            {
                A[i][j] += A[i + 1][j + 1];
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return A[0][0];
}

int main()
{

    vector<vector<int>> A{{2}, {6, 6}, {7, 8, 4}};
    cout << minimumTotal(A);

    return 0;
}