#include <bits/stdc++.h>
using namespace std;

#define ROW 18
#define COL pow(2, 18)
vector<vector<int>> dp(ROW, vector<int>(COL, -1));

int main()
{

    // vector<vector<int>> dp(3, vector<int>(8, -1));

    for (int i = 0; i < dp.size(); ++i)
    {
        for (int j = 0; j < dp[0].size(); ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << (1 << 1) << endl;

    return 0;
}