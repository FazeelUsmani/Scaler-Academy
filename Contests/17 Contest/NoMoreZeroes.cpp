#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{

    while (n > 0)
    {
        int rem = n % 10;
        n /= 10;
        if (rem == 0)
            return false;
    }

    return true;
}

string solve(int A)
{

    bool flag = true;
    int num = A + 1;
    string str;

    while (flag)
    {
        if (check(num))
        {
            str = to_string(num);
            break;
        }
        num++;
    }

    return str;
}

int main()
{
    cout << "Ans is";
    cout << solve(99) << endl;

    return 0;
}