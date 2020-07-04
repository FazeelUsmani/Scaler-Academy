#include<bits/stdc++.h>
using namespace std;

bool check (vector<vector<int>> A, int ind, int m, int n, int B){

    int j = 0;
    cout<<endl<<endl;
    for (int i = 0; i < m-ind+1; ++i){
        
        for (int k = ind-1; k < m; ++k){
            for (int l = ind-1; l < n; ++l){
                int sum = A[k][l];
                if (k-ind >= 0 && l-ind >= 0){
                    sum -= A[k-ind][l];
                    sum -= A[k][l-ind];
                    sum += A[k-ind][l-ind];
                }
                cout<<sum<<" "<<k<<" "<<l<<" "<<k-ind<<" "<<j-ind<<" "<<B<<"\n";
                
                if (sum > B)
                    return false;
            }
        }
    }
    return true;
}



int main(){ 
    int m = 3, n = 3;
    vector<vector<int>> A { {4,5,20}, {21,1,2}, {2,1,20} };
    // for (int i = 0; i < 3; ++i){
    //     for (int j = 0; j < 3; ++j){
    //         cout<<A[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;

    vector<vector<int>> prefix(m, vector<int>(n, 0) );
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (j == 0)
                prefix[i][j] = A[i][j]; 
            else
            {
                prefix[i][j] = prefix[i][j-1] + A[i][j]; 
            }
            
        }
    }

    // for (int i = 0; i < 3; ++i){
    //     for (int j = 0; j < 3; ++j){
    //         cout<<prefix[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (i != 0)
                prefix[i][j] +=  prefix[i-1][j];             
        }
    }
    // cout<<endl<<endl;
    // for (int i = 0; i < 3; ++i){
    //     for (int j = 0; j < 3; ++j){
    //         cout<<prefix[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }

    
    for (int i = 3; i > 0; --i)
        cout<<check(prefix,i,m,n, 40)<<endl;


    return 0;
}


