#include <bits/stdc++.h>
using namespace std;

void bubbleSort (vector<int> A) {
    
    int n = A.size();
    for (int i = 0; i < n-1; ++i){
        for (int j = 0; j < n-i-1; ++j){
            if (A[j] > A[j+1])
                swap(A[j], A[j+1]);
        }       
    }

    for (int x : A)
        cout<<x<<" ";
}

int main(){   
    vector<int> A {4,3,1,5,2,7,4};
    bubbleSort(A);

    return 0;
}
