#include<bits/stdc++.h>
using namespace std;

int main(){
    string A= "11111";
    int cnt = 0;
    for (char x: A)
        if (x == '1')
            cnt++;
            
    int ans = 0;
    while (cnt>0){
        ans += cnt;
        cnt--;
    }
    cout<<ans;

    return 0;
}