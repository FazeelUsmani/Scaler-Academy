#include<bits/stdc++.h>
using namespace std;

int maxCuts(int A, vector<int> &B, int N, int cost){

    if (N == 1)
        return B[1];
    // cout<<N<<" "<<cost<<endl;
    for (int i = 0; i < N; ++i){
        cost = B[i] + maxCuts(A, )
    }
    
    return cost;
}

int main(){   

    int A = 5;
    vector<int> B{3,7,7,10,12};
    cout<<maxCuts(A, B, A, 0);

    return 0;
}
