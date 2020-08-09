#include<bits/stdc++.h>
using namespace std;

int solve(int A) {

    int setBits[A+1] = {0};
    setBits[0] = 0;
    setBits[1] = 1;
    cout<<"before loop";
    
    for (int i = 2; i <= A; ++i){
        cout<<i<<"\n";
        int index = (i>>1);
        setBits[i] = setBits[index] + (i&1);        
    }
    
    int totalSetBits = 0;
    for (int x: setBits){
        cout<<x<<" ";
        totalSetBits += x;
    }
    
    return totalSetBits;
}


int main(){   

    cout<<(solve(100000));

    return 0;
}