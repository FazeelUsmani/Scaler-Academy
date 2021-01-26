/*
Maximum Sum Matrix

Problem Description

You have to create a maximum sum matrix of size N x M such that maximum of ith row is A[i] and jth coloumn is B[j]

Return the maximum total sum of the matrix. Since the answer could be large, return answer % 109 + 7.



Problem Constraints
1 <= N, M <= 105

1 <= A[i], B[j] <= 106



Input Format
First argument is an integer array A of size N.

Second argument is an integer array B of size M.

Output Format
Return an integer denoting the maximum total sum of the matrix.

Example Input
Input 1:

 A = [3, 2, 6]
 B = [4, 6]
Input 2:

 A = [1, 1]
 B = [1, 1]


Example Output
Output 1:

 20
Output 2:

 4


Example Explanation
Explanation 1:

 Matrix will be: [
                    [3, 3]
                    [2, 2]
                    [4, 6] 
                 ]
 Sum of the matrix is 20.
Explanation 2:

 Matrix will be: [
                    [1, 1]
                    [1, 1]
                 ]
 Sum of the matrix is 4.

*/

int Solution::solve(vector<int> &A, vector<int> &B)
{

    sort(A.begin(), A.end());

    int N = A.size(), M = B.size();

    vector<int> sum(N, 0);
    sum[0] = A[0];
    for (int i = 1; i < N; ++i)
    {
        sum[i] = (sum[i - 1] + A[i]) % 1000000007;
    }

    long long ans = 0;
    long long temp;

    for (int j = 0; j < M; ++j)
    {
        int index = lower_bound(A.begin(), A.end(), B[j]) - A.begin();

        temp = (B[j] * (N - index)) % 1000000007;
        temp = (temp + sum[index - 1]) % 1000000007;

        ans = (ans + temp) % 1000000007;
    }

    return int(ans) % 1000000007;
}
