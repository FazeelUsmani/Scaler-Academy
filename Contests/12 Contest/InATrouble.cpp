#include<bits/stdc++.h>
using namespace std;

void insertBS(vector<int> &A, int x){
    
    int low = 0, high = A.size() - 1;
    
    while (low<=high){
        int mid = low + (high - low)/2;
        if (A[mid] > x)
            high = mid-1;
        else if (A[mid] < x){
            low = mid+1;
        }
        else
        {
            low = mid; 
            break;           
        }        
    }
    A.insert(A.begin() + low, x);
}

vector<int> solve(){
    vector<int> A = {13,4,10,17,6,16};
    sort(A.begin(), A.end());
    
    int n = A.size();
    
    while (n--){
        int first = A[0], last = A[A.size() - 1];
        int avg = (first+last)/2;
        first += avg;
        last -= avg;
        
        A.erase(A.begin());
        A.erase(A.begin()+A.size()-1);
        
        insertBS(A, first);
        insertBS(A, last);
    }

    return A;       
}

int main(){  

    vector<int> A = solve();
    for (int x: A) 
        cout<<x<<endl;
    

    return 0;
}