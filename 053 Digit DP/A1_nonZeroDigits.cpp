#include <bits/stdc++.h>
using namespace std;

int N;
string v;

int count(int pos, int flag, int cnt, bool last)
{
    if (cnt > 3)
        return 0;
    if (pos == N)
        return (cnt <= 3);
    int ans = 0;

    if (flag & (pos == N - 1))
    {
        if (last)
        {
            int temp = int(v[pos]) - 47;
            // cout << "temp " << temp << endl;
            if (temp != 0)
            {
                v[pos] = v[pos] - 1;
            }
            // cout << "position is " << v[pos] << endl;
        }
        // cout << v << " modified string\n";
    }

    int limit = (flag ? (int(v[pos]) - 47) : 9);

    for (int i = 0; i <= limit; ++i)
    {
        ans += count(pos + 1,
                     (flag & (i == (int(v[pos]) - 47))),
                     cnt + ((i > 0) ? 1 : 0), last);
        ans %= 1000000007;
    }

    return ans;
}

vector<int> solve(vector<string> &A)
{

    vector<int> result;
    int currAns;

    for (int i = 0; i < A.size(); i += 2)
    {
        currAns = 0;
        v = A[i];
        N = A[i].size();
        // cout << "String is " << v << endl;
        int left = count(0, 1, 0, 1);
        // cout << "lt " << left << endl;

        v = A[i + 1];
        N = A[i + 1].size();
        // cout << "String is " << v << endl;
        int right = count(0, 1, 0, 0);
        // cout << "rt " << right << endl;

        int diff = right - left;
        currAns = (currAns + diff) % 1000000007;
        result.push_back(currAns);
    }

    return result;
}

int main()
{
    // vector<string> v = {"1109", "1115"};
    vector<string> v = {"66", "95", "542", "9540",
                        "744", "864", "166", "60007"};
    // vector<string> v = {"1", "10"};
    vector<int> ans = solve(v);
    cout << "Ans is ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}