#include <bits/stdc++.h>
using namespace std;

// Sorting elements alternatively
// Odd indexed and even indexed elements are sorted seperately

void bubble3Sort (vector<int> A) {
    
    int n = A.size();
    for (int i = 0; i < n-1; ++i){
        for (int j = 0; j < n-i-2; ++j){
            if (A[j] > A[j+2])
                swap(A[j], A[j+2]);
        }       
    }

    for (int x : A)
        cout<<x<<" ";
}

int main(){   
    vector<int> A {4,3,5,6,7,2};
    bubble3Sort(A);

    return 0;
}