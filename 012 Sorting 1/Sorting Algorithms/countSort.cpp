#include <bits/stdc++.h>
using namespace std;

void countSort (vector<int> A) {
    
    int n = A.size();
    
    int maxEle = INT_MIN;
    for (int x : A){        
        maxEle = max(maxEle, x);
    }
    
    vector<int> freq(maxEle + 1, 0);
    vector<int> prefixSum(maxEle + 1, 0);
    for (int x : A){
        freq[x]++;
    }   
    
    prefixSum[0] = freq[0];
    for (int i = 1; i < freq.size(); ++i)
        prefixSum[i] = prefixSum[i-1] + A[i];

    vector<int> res(n, 0);
    for (int i = n-1; i >= 0; --i){
        int idx = --prefixSum[A[i]];
        res[idx] = A[i];     
        cout<<i<<" "<<res[i]<<" "<<A[i]<<endl;   
    }
    
    for (int x : A)
        cout<<x<<" ";
    cout<<endl;
    for (int x : res)
        cout<<x<<" ";
}

int main(){   
    vector<int> A {4,2,2,0,1,2,4,3,2,1};
    countSort(A);

    return 0;
}
