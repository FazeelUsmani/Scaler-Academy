#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A) {
    
    sort(A.begin(), A.end());
    priority_queue <int, vector<int>, greater<int> > pq;
    
    pq.push(A[0][1]);
    int rooms = 1;
    
    for (int i = 1; i < A.size(); ++i){
        if (A[i][0] < pq.top())
            rooms++;
        else
            pq.pop();
        pq.push(A[i][1]);
    }
    
    return rooms;
}


int main(){   

    vector<vector<int>> A{ {1,18}, {18,23}, {15,29}, {4,15}, {2,11}, {5,13} };
    cout<<solve(A);


    return 0;
}