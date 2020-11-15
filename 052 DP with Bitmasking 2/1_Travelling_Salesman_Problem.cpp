#include <bits/stdc++.h>
using namespace std;

void tsp(vector<vector> arr, int n, int cost, int &mncost,
         int count, bool vis[], int pos)
{
    if (count == n)
    {
        cost += arr[pos][0];
        if (cost < mncost)
            mncost = cost;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[pos][i] > 0 && !vis[i])
        {
            vis[i] = true;
            tsp(arr, n, cost + arr[pos][i], mncost, count + 1, vis, i);
            vis[i] = false;
        }
    }
}

int Solution::solve(int A, vector<vector> &B)
{
    bool vis[A];
    for (int i = 0; i < A; i++)
        vis[i] = false;
    vis[0] = true;
    int cost = 0, mncost = INT_MAX;
    int count = 1, pos = 0;
    tsp(B, A, 0, mncost, count, vis, pos);

    return mncost;
}

int main()
{

    return 0;
}