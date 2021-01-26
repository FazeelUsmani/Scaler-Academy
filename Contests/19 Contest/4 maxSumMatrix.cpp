/*


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
