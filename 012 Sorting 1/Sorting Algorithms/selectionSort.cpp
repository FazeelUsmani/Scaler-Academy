#include <bits/stdc++.h>
using namespace std;

void selectionSort (vector<int> A) {
    
    int n = A.size(), min;
    for (int i = 0; i < n; ++i){
        min = i;
        for (int j = i; j < n; ++j){
            if (A[j] < A[min])
                min = j;
        }
        swap(A[i], A[min]);
    }

    for (int x : A)
        cout<<x<<" ";
}

int main(){   
    vector<int> A {4,3,1,5,2,7,4};
    selectionSort(A);

    return 0;
}
