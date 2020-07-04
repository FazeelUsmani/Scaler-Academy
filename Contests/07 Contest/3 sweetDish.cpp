#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    
    for (int i = 2; i*i <= n; ++i){
        if (n%i == 0)
            return false;
    }
    return true;
}

int solve(vector<int> &A, int B, int C) {
    
    int n = A.size();
    int prime[n];
    memset(prime, 0, sizeof(prime));
    
    for (int i = 0; i < n; ++i){
        if (check(A[i]) == true){
            prime[i] = 1;
        }
    }
            
            
    int ans = 0, sum = 0, flag = 0;
    
    for (int i = 1; i < (1 << n); ++i){
        sum = 0;
        flag = 0;
        for (int j = 0; j < n; ++j){
            if (i & (1 << j)){
                sum += A[j];
                if (prime[j])
                    flag = 1;
            }
        }
        if (sum >= B && sum <= C && flag == 1){
            ++ans;                
        }
            
    }
    
    return ans;
}


int main(){ 

    vector<int> A = {2,2,4,5};
    int B = 3, C = 7;

    cout<<solve(A, B, C);


        
    return 0;
}
