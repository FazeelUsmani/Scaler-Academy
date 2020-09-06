#include<bits/stdc++.h>
using namespace std;

int uniString(string A){
    int n = A.size();
    if (n == 0)
        return 0;
        
    int left[n], right[n];
    if (A[0])
    left[0] = (A[0]=='0')? 0 : 1;
        
    for (int i = 1; i < n; ++i){
        if (A[i] == '1'){
            left[i] = 1 + left[i-1];
        }
        else{
            left[i] = left[i-1];
        }
    }
    
    left[0] = (A[0]=='0')? 0 : 1;
    right[n-1] = (A[n-1]=='0')?0:1;

    for (int i = n-2; i >= 0; --i){
        if (A[i] == '1'){
            right[i] = 1 + right[i+1];
        }
        else{
            right[i] = right[i+1];
        }
    }

    for (int x : left)
        cout<<x<<", ";
    cout<<endl;
    
    for (int x : right)
        cout<<x<<", ";
    cout<<endl;

    int res = 0;
    for (int i = 0; i < n; ++i){
        int ans = left[i]+right[i];
        cout<<i<<" | "<<left[i]<<" | "<<right[i]<<" | "<<ans<<", "<<res<<endl;
        res = max(res, ans);
    }
    
    int maxCnt = 0, cnt = 0;
    for (int i = 0; i < n; ++i){
        if (A[i] == '0')
            cnt++;
        else
        {
            cnt = 0;
        }
        maxCnt = max(maxCnt, cnt);        
    }
    cout<<maxCnt<<", ";

    return res+maxCnt+1;
}

int main(){

    string A = "111101011101111110110101100001011100000100111111011001011";
    cout<<uniString(A)<<", ";

    return 0;
}