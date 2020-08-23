#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int A, int B, int C, int D) {
    
    if (D == 0)
        return 0;
    
    if (D == 1){
        ll ans = (A)%1000000007;
        ans = (ans + B)%1000000007;
        ans = (ans + C)%1000000007;
        return int(ans);
    }
    
    ll ans = 1;
    int mid = 0, cnt = 0;

    vector<ll> arr = {1};
    
    for (int i = 2; i <= D; ++i){
        ll curr = 0;
        curr = (arr[mid] * A);
        curr = (curr + (B*i));
        curr = (curr + C);
        curr %= 1000000007;
        cnt++;
        if (cnt%2 == 0){
            cnt = 0;
            mid++;
        }
        arr.push_back(curr);
        bool flag = false;
        if (ans == 266506762){
            cout<<"woohoo got it! "<<i;
            flag = true;
        }
        //cout<<i<<" "<<ans<<endl;
        ans = (ans + curr)%1000000007;
    }

    // for (ll x: arr)
    //     ans = (ans + x)%1000000007;
        
    return ans;
}

int main(){

    int A = 325520046, B = 61630350, C = 838064403, D= 100000;

    cout<<solve(A,B,C,D);
    // 266506762

    return 0;
}