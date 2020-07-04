#include<bits/stdc++.h>
using namespace std;

int powerArrays (vector<int> &A, int n){

    int nge[n], pge[n];
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; ++i){
        while (!s.empty() && A[s.top()]/2 < A[i]){
            nge[ s.top() ] = i;
            s.pop(); 
        }
        s.push(i);
    }
    
    while (!s.empty()){
        nge[s.top()] = n;
        s.pop();
    }
    for (int x : nge)
        cout<<x<<" ";
    cout<<endl;


    cout<<"Prev greater element\n";
    s.push(n-1);
    for (int i = n-2; i >= 0; --i){
        while (!s.empty() && A[s.top()]/2 < A[i]){
            pge[ s.top() ] = i;
            s.pop();
        }
        s.push(i);
    }
    
    while (!s.empty()){
        pge[ s.top() ] = -1;
        s.pop();
    }        
    for (int x : pge)
        cout<<x<<" ";
    cout<<endl;

    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans += (i-pge[i]) * (nge[i]-i) - 1;
    }

    return ans;
}

int main(){ 

    vector<int> A{6,4,9,2,3,8};
    cout<<"\nThere are "<<powerArrays(A, A.size())<< " power arrays\n";
    
        
    return 0;
}
