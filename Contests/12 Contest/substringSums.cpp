#include<bits/stdc++.h>
using namespace std;
// Scooby Doo 

typedef long long ll;
ll ans;

ll power1(ll a, ll b){
    ll res = 1;
    a = a%1000000007;
    while (b>0){
        if (b&1)
            res = (res*a)%1000000007;
        b = b>>1;
        a = (a*a)%1000000007;
    }
    return res;
}

void addDigit(int n, int pos, int tot){

    ll res = 0;
    int x = tot-pos+1;    

    while (x--){
        res = (res*10 + n)%1000000007;
    }
   
    res = (res*pos)%1000000007;

    ans = (ans+res) % 1000000007;
}

int solve(string A) {
    ans = 0;
    int pos = A.size();
    int tot = pos;
    
    for (int i = pos-1; i >= 0; i--){
        int currNum = int(A[i]-'0');
        addDigit(currNum, pos, tot);
        pos--;
    }
    
    return ans;
}

int main(){   
    
    cout<<solve("12345")<<endl;
    

    return 0;
}