/*

Palindromic Beauty
Problem Description

The palindromic beauty of a set of numbers is the number of palindromes in a set. A number is a palindrome that remains the same when its digits are reversed. The number should be considered without leading zeroes.

You have to solve q queries. You are given a list A of strings. List A contains numbers in string format. The ith query consists of numbers A[2*i] and A[2*i+1]. The answer to ith query is the palindromic beauty of set of numbers from A[2*i] to A[2*i+1]. Since the answer can be large, return it modulo 109 + 7.



Problem Constraints
2 <= |A| <= 400

|A| is even

1 <= |A[i]| <= 17

A[i] does not contain leading zeroes 



Input Format
The first line of input contains A- list of numbers in string format.



Output Format
Return  a vector of size q- ith of which contains the answer for ith query.



Example Input
Input 1:

  A = ["1", "5", "7", "12"]
Input 2:

  A = ["1", "100"]


Example Output
Output 1:

  [5, 4]
Output 2:

  18


Example Explanation
Explanation 1:

  In the first query, all numbers from 1 to 5 are palindromes.
  In the second query, 7, 8, 9 and 11 are palindromes.   
Explanation 2:

  Palindromes in the range are- 
  1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99

*/

/*
Solution Logic: 

The basic idea is while traversing through the numbers we can keep another 
pointer J (where J initially points to the last digit of the number). 
This pointer will gradually decrease. We will simply try to put the digit 
(that we are currently generating in our recursive function) at the Jth position 
of the number. This will ensure the number is a palindrome. 
Now the tricky part is how to validate the generated number at the base case?
For this, we need to keep another flag in our state. 
This flag will be very similar to the Basic Digit DP flag and will be kept
for the J pointer. This flag will tell us if we have set any illegal digit 
using J pointer. In my code, I have used this flag to determine whether the 
number that I have generated till current J pointer, is bigger than the actual
number until the current J pointer or not. In the base case, by combining both 
the flags’ status we can easily determine whether the current generated number 
is larger than the actual number or not. I also used another flag, which tells if 
the first digit of the number is non-zero. This was used to prevent the J pointer 
from putting illegal 0 at the end of the number (when the actual number generation
has not yet started to generate).


DP states will be dp[start][end][startFlag][endFlag] (dp[N][N][2][2])?

*/

#include <bits/stdc++.h>
using namespace std;

int len; /// total len
int digitUp[20];
void toDigUpper(long long x)
{
    stack<int> stk;
    while (x > 0)
    {
        stk.push(x % 10);
        x /= 10;
    }
    if (stk.empty())
        stk.push(0);
    while (!stk.empty())
    {
        digitUp[len++] = stk.top();
        stk.pop();
    }
}

long long dp[17][17][2][2][2];
long long rec(int pos, bool noLimitOfPrvPos, bool startHoise, int backPos, bool boroNisi)
{
    if (pos > backPos)
    {
        if (!noLimitOfPrvPos && boroNisi)
            return 0;
        return 1;
    }

    if (dp[pos][backPos][noLimitOfPrvPos][startHoise][boroNisi] != -1)
        return dp[pos][backPos][noLimitOfPrvPos][startHoise][boroNisi];

    int limit;
    if (noLimitOfPrvPos == true)
        limit = 9;
    else
        limit = digitUp[pos];

    long long ret = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (startHoise == 0 && i == 0)
        {
            ret += rec(pos + 1, noLimitOfPrvPos || i < digitUp[pos], 0, backPos, boroNisi);
        }
        else if (pos == backPos)
        {
            ret += rec(pos + 1, noLimitOfPrvPos || i<digitUp[pos], startHoise | i> 0, backPos, boroNisi);
        }
        else
        {
            if (i == digitUp[backPos])
            {
                ret += rec(pos + 1, noLimitOfPrvPos || i<digitUp[pos], startHoise | i> 0,
                           backPos - 1, boroNisi);
                continue;
            }

            ret += rec(pos + 1, noLimitOfPrvPos || i<digitUp[pos], startHoise | i> 0,
                       backPos - 1, i > digitUp[backPos]);
        }
    }
    dp[pos][backPos][noLimitOfPrvPos][startHoise][boroNisi] = ret;
    return ret;
}

long long getAns(long long x)
{
    if (x < 0)
        return 0;
    if (x < 10)
        return x + 1;
    memset(dp, -1, sizeof(dp));
    len = 0;
    toDigUpper(x);
    return rec(0, false, 0, len - 1, false);
}

vector<int> Solution::solve(vector<string> &A)
{
    vector<int> ans;
    for (int i = 0; i < A.size(); i += 2)
        ans.push_back((getAns(stoll(A[i + 1])) - getAns(stoll(A[i]) - 1)) % 1000000007);
    return ans;
}