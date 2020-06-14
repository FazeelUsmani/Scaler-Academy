int Solution::isMatch(const string s, const string p) {
    
    int n = s.length(), m = p.length();

    if (m == 0)
        return (n == 0);

    vector<vector<int>> match(n+1, vector<int> (m+1, 0));
    match[0][0] = 1;

    for (int j = 1; j <= m; ++j)
        if (p[j-1] == '*')
            match[0][j] = match[0][j-1];


    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){

            if (p[j-1] == '*')
                match[i][j] = match[i][j-1] || match[i-1][j];
                
            else if (p[j-1] == '?' || s[i-1] == p[j-1])
                match[i][j] = match[i-1][j-1];

            else
                match[i][j] = 0;
            
        }
    }
    
    return match[n][m];
}
