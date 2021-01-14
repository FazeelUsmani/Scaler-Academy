#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int merge(vector<int> &A, vector<int> &temp, int left, int mid, int right)
{
    int i, j, k, cnt = 0;
    i = left;
    k = left;
    j = mid;

    while ((i < mid) && (j <= right))
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            cnt += (mid - i);
            cnt %= MOD;
        }
    }

    while (i < mid)
        temp[k++] = A[i++];
    while (j <= right)
        temp[k++] = A[j++];

    for (int x = left; x <= right; ++x)
        A[x] = temp[x];

    return cnt;
}

int mergeSort(vector<int> &A, vector<int> &temp, int left, int right)
{
    int mid, cnt = 0;
    if (right > left)
    {
        mid = left + (right - left) / 2;
        cnt = (cnt + mergeSort(A, temp, left, mid)) % MOD;
        cnt = (cnt + mergeSort(A, temp, mid + 1, right)) % MOD;

        cnt = (cnt + merge(A, temp, left, mid + 1, right)) % MOD;
    }
    return cnt % MOD;
}

int solve(vector<int> &A)
{

    int n = A.size();
    vector<int> temp(n, 0);

    return mergeSort(A, temp, 0, n - 1);
}

int main()
{
    vector<int> A{1, 6, 4, 5};
    cout << (solve(A));

    return 0;
}
