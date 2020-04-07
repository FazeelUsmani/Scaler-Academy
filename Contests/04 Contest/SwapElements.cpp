#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A{-1,-2,-3,4,5};
    int n = A.size();
    vector<int> neg, pos;
    
    for (int i = 0; i < n; i++){
        if (A[i] < 0)
            neg.push_back( A[i] );
        else
            pos.push_back( A[i] );
    }
    
    int s1 = neg.size(), s2 = pos.size();
    
    if (s1 == 0)
        return pos;
    if (s2 == 0)
        return neg;
    
    int ind = 0, i = 0, j = 0;
    while ( i < s1 && j < s2 ){
        A[ind] = neg[i];
        i++;
        ind++;
        A[ind] = pos[i];
        j++;
        ind++;
    }
    
    while (i < s1){
        A[ind] = neg[i];
        i++;
        ind++;
    }
    
    while ( j < s2){
        A[ind] = pos[j];
        j++;
        ind++;
    }
        
    for (auto x : A)
        cout<<x<<" ";


    return 0;
}
