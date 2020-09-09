#include <bits/stdc++.h>
using namespace std;

void insertionSort (vector<int> A) {
    
    int n = A.size(), j, key;
    for (int i = 1; i < n; ++i){
        key = A[i];
        j = i-1;        
        while (j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }

    for (int x : A)
        cout<<x<<" ";
}

int main(){   
    vector<int> A {4,3,1,5,2,7,4};
    insertionSort(A);

    return 0;
}
