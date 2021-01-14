vector<int> Solution::subUnsort(vector<int> &A)
{
    int leftMax = A[0];
    int rightMin = A[A.size() - 1];
    int r = -1, l = -1;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] < leftMax)
            r = i;
        else
            leftMax = A[i];
    }

    for (int j = A.size() - 2; j >= 0; --j)
    {
        if (A[j] > rightMin)
            l = j;
        else
            rightMin = A[j];
    }

    if (l == -1 || r == -1)
        return {-1};
    return {l, r};
}