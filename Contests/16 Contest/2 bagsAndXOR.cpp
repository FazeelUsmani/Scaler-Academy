#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{

    int n = A.size();

    int i = 0, j = n - 1;
    int ans = 0;
    vector<int> blue, red;

    while ((i < (n / 2)) && (j >= (n / 2)))
    {
        if (A[i] > A[j])
        {
            red.push_back(A[i]);
            blue.push_back(A[j]);
        }
        else
        {
            red.push_back(A[j]);
            blue.push_back(A[i]);
        }
        i++;
        j--;
    }

    i = 0;
    j = blue.size() - 1;

    while (i < red.size())
    {
        ans += (red[i] ^ blue[j]);
        i++;
        j--;
    }

    return ans;
}

int main()
{
    vector<int> A{23, 35, 6, 25, 10, 34,
                  29, 13, 35, 1, 6, 7};
    cout << "Ans is " << solve(A);

    return 0;
}
