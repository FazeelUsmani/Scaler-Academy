#include <bits/stdc++.h>
using namespace std;
int tree[4*4];
vector<int> arr;

int constructST (int ss, int se, int si){
    if (ss == se){
        tree[si] = arr[ss];
        return arr[ss];    
    }
    int mid = ss + (se-ss)/2;
    tree[si] = constructST (ss, mid, 2*si + 1) + constructST (mid+1, se, 2*si+2);

    return tree[si];
}

int getSum (int qs, int qe, int ss, int se, int si){  // qs - query start, qe - query end
    if (se < qs || ss > qe)
        return 0;
    
    if (qs <= ss && qe >= se)
        return tree [si];
        
    int mid = ss + (se-ss)/2;

    return getSum (qs, qe, ss, mid, 2*si+1) + getSum (qs, qe, mid+1, se, 2*si+2);
}

void update (int ss, int se, int i, int si, int diff){
    if ( i < ss || i > se)
        return;

    if (ss == se){
        tree[si] += diff;
        arr[i] += diff;
    }
    tree[si] = tree[si] + diff;

    if (se > ss){
        int mid = (ss + (se-ss)/2);
        update (ss, mid, i, 2*si+1, diff);
        update (mid+1, se, i, 2*si+2, diff);        
    }

}


int main(){

    //arr = {10,20,30,40,50};
    arr = {10, 20, 30, 40};
    
    int n = arr.size();
    int ss = 0, se = n-1;       
    cout<<constructST (ss, se, 0)<<endl;
    
    for (int x : tree)
        cout<<x<<" ";
    cout<<endl;

    cout<<getSum (2,4, ss, se, 0);
    
    cout<<"\nTree is going to Update\n";   //update (1, 25) --> Replacing the index value in tree as 25
    // diff =  25 - arr[i]

    update (ss, se, 1, 0, 25 - arr[1]);   

    cout<<"Printing Tree after update\n";
    for (int x : tree)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
