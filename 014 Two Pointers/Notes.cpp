This file contains all the codes for the problems explained in the class:


1) Given a sorted array, return i,j for any pair of A[i]+A[j] = k

// T.C: O(n)
    
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A{1,3,5,10,20,23,30};
    int n = A.size();
    int k = 15, i = 0, j = n-1;

    while (i < n && j >= 0){
        int sum = A[i]+A[j];
        if (sum == k){
            cout<<"indices are "<<i<<" & "<<j<<" The numbers are "<<A[i]<<" + "<<A[j]<<" = " <<k;
            break;
        }

        else if (sum > k)
            j--;

        else
            i++;  
    }  
    return 0;
}




2) Given a sorted array, return i,j for any pair of A[j]-A[i] = k

#include<bits/stdc++.h>

using namespace std;


int main(){
    
    vector<int> A{1,3,5,10,20,23,30};
    int n = A.size();
    int k = 15, i = 0, j = 1;

    while (j!=n){
        int diff = A[j]-A[i];
        
        if (diff == k){
            cout<<"indexes are "<<i<<" & "<<j<<" The numbers are "<<A[j]<<" - "<<A[i]<<" = " <<k;
            break;
        }

        else if (diff > k)
            i++;

        else
            j++;  
    }       

    return 0;
}



