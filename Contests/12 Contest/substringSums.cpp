#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int solve(string A) {
    int n = A.length();
    
    vector<vector<ll> > dp(n, vector<ll> (n, 0));
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        dp[0][i] = int(A[i]-'0');
        ans = (ans+dp[0][i])%MOD;
    }
        
    for (ll i = 1; i < n; ++i){
        for (ll j = i; j < n; ++j){
            dp[i%2][j] = (dp[(i-1)%2][j-1]*10 + A[j]-'0')%MOD; 
            ans = (ans + dp[i%2][j])%MOD;
        }
    }
    
    for (ll i = 0; i < n; ++i){
        for (ll j = 0; j < n; ++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //597988838

    return ans%MOD;
}
int main(){   
    //cout<<solve("972698438521");

    for (int i = 0; i < 5; ++i){
        for (int j = i; j < 5; ++j){
            cout<<i<<j<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}