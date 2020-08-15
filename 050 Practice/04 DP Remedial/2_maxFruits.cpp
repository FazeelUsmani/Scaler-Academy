#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    
    
    long long n = A.size();
    long long maxFruits[n] = {0};
    maxFruits[0] = max(0, A[0]);
    
    for (int i = 1; i <= B; ++i)
        maxFruits[i] = max(maxFruits[i-1], A[i]);
    
    for (long long i = B+1; i < n; ++i){
        maxFruits[i] = max(maxFruits[i-B+1]+A[i], maxFruits[i-1]);    
    }
    
    return maxFruits[n-1];
}


int main(){   

    vector<int> A {1, 2, -3, -5, 4, 6, -3, 2, -1, 2 };
    cout<<"Ans is "<<solve(A, 1);

    return 0;
}