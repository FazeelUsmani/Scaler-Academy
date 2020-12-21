#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A = 8;

    vector<bool> isprime(A + 1, true);
    isprime[0] = isprime[1] = 0;

    for (int i = 2; i <= A; ++i)
    {
        for (int j = 2 * i; j <= A; j += i)
        {
            isprime[j] = false;
        }
    }

    for (bool x : isprime)
        cout << x << " ";
    cout << endl;
    vector<int> prime(A + 1, 0);

    for (int i = 2; i <= A; ++i)
    {
        if (isprime[i])
        {
            for (int j = 2 * i; j <= A; j += i)
            {
                prime[j]++;
            }
        }
    }

    int lucky = 0;
    for (int i = 0; i <= A; ++i)
    {
        if (prime[i] == 2)
        {
            lucky++;
        }
    }

    for (int i = 0; i <= 12; ++i)
        cout << i << " ";
    cout << endl;
    for (int x : prime)
        cout << x << ", ";

    cout << endl;
    cout << lucky;

    return 0;
}