#include<iostream>

using namespace std;

int *dp;

int fib(int n){
    if (dp[n] == -1){
        int res;
        if (n == 0 || n == 1)
            return n;
        else
            res = fib(n-1)+fib(n-2);
        dp[n] = res;
    }
    
    return dp[n];
}


int main()  {
    
    int n;
    cin>>n;
    dp = new int[n+1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
        
    cout<<fib(n)<<endl;
    
    return 0;
}
