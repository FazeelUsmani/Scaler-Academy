/*

kth character in double decrypted string
Given a String A and an integer B. String A is encoded consisting of lowercase English letters and numbers. A is encoded in a way where repetitions of substrings are represented as substring followed by the count of substrings.

For example: if the encrypted string is “ab2cd2” and B=6, so the output will be ‘d’ because the decrypted string is “ababcdababcd” and 4th character is ‘b’.

You have to find and return the Bth character in the decrypted string.

Note: Frequency of encrypted substring can be of more than one digit. For example, in “ab12c3”, ab is repeated 12 times. No leading 0 is present in the frequency of substring.

Input Format

The arguments given are string A and integer B.
Output Format

Return the Bth character in the decrypted string.
Constraints

1 <= length of the array <= 10^5
1 < = K < = 10^9
For Example

Input 1:
    A = "ab2c3"
    B = 8
Output 1:
    a
    Decrypted string will be "ababcababcababc" and 'a' is the 8th character.

Input 2:
    A = "x2y3"
    B = 3
Output 2:
    y
    Decrypted string will be "xxyxxyxxy"

*/

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