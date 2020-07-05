#include<bits/stdc++.h>
using namespace std;

bool checkBoring(string s){
    bool flag = true;
    for (int i = 1; i < s.size(); ++i){
        flag &= (abs(s[i] - s[i-1]) != 1);
    }
    return flag;
}

int solve(string A) {

    string odd = "", even ="";
    for (int i = 0; i < A.size(); ++i){
        if (A[i]%2 == 0)
            even += A[i];
        else
            odd += A[i];   
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());  

    if (checkBoring(even + odd) || checkBoring(odd + even))  
        return 1;
    return 0;     
}

int main(){
    cout<<solve("gbedggcjac");

    return 0;
}