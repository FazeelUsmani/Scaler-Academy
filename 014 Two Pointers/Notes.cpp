This file contains all the codes for the problems explained in the class:

1) Given a sorted array, return i,j for any pair of A[i]+A[j] = k


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A{1,3,5,10,20,23,30};
    int n = A.size();
    int k = 15, i = 0, j = n-1;

    while (i < n && j >= 0){
        int sum = A[i]+A[j];
        if (sum == k){
            cout<<"indexes are "<<i<<" & "<<j<<" The numbers are "<<A[i]<<" + "<<A[j]<<" = " <<k;
            break;
        }

        else if (sum > k)
            j--;

        else
            i++;  
    }  
    return 0;
}



