
vector<vector<bool>> find_all_palindromes(const string& text) {
    int n = text.size();
    vector<vector<bool>> palindromes(n, vector<bool>(n, false));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                palindromes[i][j] = true;
            }
            else if(text[i] == text[j]) {
                if(j - i == 1) {
                    palindromes[i][j] = true;
                }
                else {
                    palindromes[i][j] = palindromes[i + 1][j - 1];
                }
            }
        }
    }

    return palindromes;
}

// Time - O(N^2), Space - O(N^2)
int Solution::minCut(string A) {
    int n = A.size();
    if(n == 0) {
        return 0;
    }

    vector<vector<bool>> palindromes = find_all_palindromes(A);
    vector<int> dp(n);

    for(int i = 0; i < n; i++) {
        dp[i] = INT_MAX;
        if(palindromes[0][i]) {
            dp[i] = 0;
        }
        else {
            for(int j = i; j > 0; j--) {
                if(palindromes[j][i]) {
                    dp[i] = min(dp[j - 1] + 1, dp[i]);
                }
            }
        }
    }

    return dp[n - 1];
}
