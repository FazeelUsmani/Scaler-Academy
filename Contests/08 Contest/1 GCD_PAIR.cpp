#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0)
        return b;
    return (b%a, a);
}

int main(){ 

    vector<int> A{5,7,10,8,3,4};

    for (int i = 0; i < 6; i+=2)
        cout<<gcd(A[i], A[i+1])<<" ";


    return 0;
}
