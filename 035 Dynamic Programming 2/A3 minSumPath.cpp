int m = A.size(), n = A[0].size();

    cout<<m<<" "<<n<<"\n";

    vector<vector<int>> minSum(m, vector<int> (n, 0));

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            int sum = 0;
            if (i == 0 || j == 0){
                if (i == 0 && j == 0){
                    minSum[i][j] = A[i][j];
                }
                else if (i == 0){
                    minSum[i][j] = A[i][j] + minSum[i][j-1];
                }
                else if (j == 0){
                    minSum[i][j] = A[i][j] + minSum[i-1][j];
                }
            }
            
            else
            {
                minSum[i][j] = A[i][j] + min(minSum[i-1][j], minSum[i][j-1]);
            }          
        }
    }
    /*
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cout<<minSum[i][j]<<" ";
        }
        cout<<endl;
    }
    */
   
    return minSum[m-1][n-1];
