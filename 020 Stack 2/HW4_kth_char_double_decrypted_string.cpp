#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int num;
    string str;
    string solve(string, int);
};

string Solution::solve(string A, int B)
{

    stack<pair<char, int>> s;
    int n = A.size();
    long long int len = 0;

    for (int i = 0; i < n;)
    {

        if (isalpha(A[i]))
        {
            len++;
            s.push(make_pair(A[i], len));
            i++;
        }

        else if (isdigit(A[i]))
        {
            int num = 0;
            while (i < n && isdigit(A[i]))
            {
                num = num * 10 + (A[i] - '0');
                i++;
            }
            len = len * num;
        }
        if (len > B)
            break;
    }

    while (!s.empty())
    {
        char ch = s.top().first;
        int x = s.top().second;

        B = B % x;
        if (B == 0)
            return (string) "" + ch;
        s.pop();
    }
}

int main()
{
    Solution x;
    string A = "ab2c3";
    int B = 8;

    cout << x.solve(A, B);

    return 0;
}