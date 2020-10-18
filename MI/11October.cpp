int pos, neg;

void backtrack(vector<int> &A, int pos, int C, vector<int> visited, int val)
{

    if (pos == 0)
    {
        if (val > C)
            neg--;
        else
            pos++;
    }

    if (visited.size() & 1)
    {
        backtrack(A, pos - 1, C, visited, A[0]);

        int middle = visited.size() / 2;
        backtrack(A, pos - 1, C, visited, A[visited[middle]]);

        backtrack(A, pos - 1, C, visited, A[visited[visited.size() - 1]]);
    }
    else
    {
        backtrack(A, pos - 1, C, visited, A[0]);

        backtrack(A, pos - 1, C, visited, A[visited[visited.size() - 1]]);
    }
}

int Solution::solve(vector<int> &A, int B, int C)
{
    pos = 0;
    neg = 0;

    vector<int> visited;
    for (int i = 0; i < A.size(); ++i)
        visited.push_back(i);

    backtrack(A, B, C, visited, INT_MAX);

    return (pos / (pos + reg)) % 1000000007;
}
