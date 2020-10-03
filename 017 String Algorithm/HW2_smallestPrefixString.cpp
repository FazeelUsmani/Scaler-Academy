#include <bits/stdc++.h>
using namespace std;

string compute(string A, string B)
{

    int n = A.size(), m = B.size();
    int i = 1, j = 0;
    string temp;
    temp.push_back(A[0]);

    if (i < n && A[i] < B[j])
    {
        temp.push_back(A[i++]);
        while (A[i] < B[j])
        {
            temp.push_back(A[i++]);
        }
        temp.push_back(B[j]);
    }
    else
    {
        temp.push_back(B[j++]);
        while (j < m && B[j] < A[i])
        {
            temp.push_back(B[j++]);
        }
        temp.push_back(A[i]);
    }

    return temp;
}

string smallestPrefix(string A, string B)
{

    int n = A.size(), m = B.size();
    int i = 0, j = 0;

    string ans1 = compute(A, B);
    string ans2 = compute(B, A);
    cout << "\n"
         << ans1 << "  " << ans2;
    if (ans1.size() < ans2.size())
        return ans1;
    return ans2;
}

int main()
{

    string A = "ababa", B = "ahahahah";
    cout << smallestPrefix(A, B);

    return 0;
}