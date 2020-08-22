#include<bits/stdc++.h>
using namespace std;

int maxCuts(int A, vector<int> &B){
   
    
    int maxCut[A+1];
    maxCut[0] = 0;
    int i, j;
    
    for (i = 1; i <= A; ++i){
        int maxVal = INT_MIN;
        for (j = 0; j < i; ++j)
            maxVal = max(maxVal, B[j] + maxCut[i-j-1]);
        maxCut[i] = maxVal;
    }

    return maxCut[A];
}

int main(){   

    int A = 5;
    vector<int> B{3,7,7,10,12};
    cout<<maxCuts(A, B);

    return 0;
}
