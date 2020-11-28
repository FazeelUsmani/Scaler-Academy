// https://leetcode.com/problems/sliding-window-maximum/
// Asked in Google for SDE-2
// Can do it using DP but the charter of this problem is to use dequeue [DEQ]

#include <bits/stdc++.h>
using namespace std;

#include <deque>

vector<int> solve(vector<int> &A, int k)
{
    int _max = INT_MIN;
    vector<int> ans;
    for (int i = 0; i < k; ++i)
    {
        _max = max(_max, A[i]);
    }
    ans.push_back(_max);
    deque<int> dq;
    dq.push_back(_max);

    for (int i = k; i < A.size(); ++i)
    {
        if (dq.empty())
        {
            dq.push_back(i);
            _max = A[i];
        }
        else
        {
            while (!dq.empty() && A[dq.front()] < A[i])
            {
                dq.pop_front();
            }
            if (dq.empty())
            {
                _max = A[i];
            }
            else
            {
                _max = max(_max, A[i]);
            }
            dq.push_front(A[i]);
            ans.push_back(_max);
        }
    }

    return ans;
}

int main()
{
    vector<int> A{1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> ans = solve(A, 3);

    for (int x : ans)
        cout << x << " ";

    return 0;
}