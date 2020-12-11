/*

Victory
Problem Description

Given three integers A, B, C.

Probability of India winning a match against Pakistan is 1/B.

Find the probability P of India winning Cth match in its Ath Match against Pakistan. If P = Q/R, return (Q * (R-1)) modulo 109+7.

NOTE: India should win Ath match and that should be Cth win of India in total.



Problem Constraints
1 <= A <= 109
1 <= B <= 102
1 <= C <= 109
1 <= C <= A
0 <= A - C <= 106


Input Format
The first argument given is integer A.

The Second argument given is integer B.

The Third argument given is integer C.



Output Format
Find the probability P of India winning Cth match in its Ath Match against Pakistan.

If P = Q/R, return (Q * (R-1)) modulo 109+7.



Example Input
Input 1:

 A = 2
 B = 2
 C = 2
Input 2:

 A = 3
 B = 3
 C = 2


Example Output
Output 1:

 250000002
Output 2:

 481481485


Example Explanation
Explanation 1:

 P = W W = ( 1/2 )*( 1/2 ) = 1/4 = (1) * (4-1) mod 109+7 = 250000002
Explanation 2:

 P = W L W + L W W = ( 1/3 ) * ( 2/3 ) * ( 1/3 ) + ( 2/3 ) * ( 1/3 ) * ( 1/3 ) = 4/27



*/

#define ll long long
#define MOD 1000000007

ll power1(ll a, ll b)
{
    ll res = 1LL;
    while (b)
    {
        if (b & 1)
        {
            res = ((res % MOD) * (a % MOD)) % MOD;
            b--;
        }
        else
        {
            a = ((a % MOD) * (a % MOD)) % MOD;
            b = b / 2;
        }
    }
    return res % MOD;
}

int Solution::solve(int A, int B, int C)
{

    ll n = A - 1, p = C - 1, a = 1LL, b = 1LL;

    for (ll i = p + 1; i <= n; ++i)
    {
        a = ((a % MOD) * (i % MOD)) % MOD;
        a %= MOD;
    }

    for (ll i = 1; i <= n - p; ++i)
    {
        b = ((b % MOD) * (i % MOD)) % MOD;
        b %= MOD;
    }

    ll c = power1(B, A);
    ll d = power1(B - 1, A - C);

    b = ((b % MOD) * (c % MOD)) % MOD;
    a = ((a % MOD) * (d % MOD)) % MOD;

    ll e = power1(b, MOD - 2LL);

    ll ans = ((a % MOD) * (e % MOD)) % MOD;

    return ans;
}