#include<bits/stdc++.h>
using namespace std;

// int solve(int A, vector<int> &B, vector<vector<int> > &C) {
    
//     int index[2*A] = {0};
//     for (int i = 0; i < 2*A; ++i){
//         index[ B[i] ] = i;
//     }
    
//     int cnt = 0;
//     for (vector<int> x: C){
        
//         int firstIndex = index[x[0]];
//         int secondIndex = index[x[1]];
//         if (abs(firstIndex-secondIndex) == 1)
//             continue;
//         cnt++;
//     }
    
//     return (cnt==0) ? 0 : cnt-1;
// }

// int main(){   

//     int A = 9;
//     vector<int> B {11,13,18,3,5,14,8,6,15,1,17,2,4,16,9,10,12};
//     vector<vector<int> > C { {7, 9}, {6, 1}, {18, 5}, {12, 17}, {10, 13}, 
//     {2, 15}, {16, 3}, {8, 4}, {14, 11} };

//     cout<<solve(A, B, C);

//     return 0;
// }
/*

There are A pairs and therefore 2A people. Each person has a unique number ranging from 1 to 2A. An array of integers B shows the arrangement of these 2A people.

A matrix C of size A x 2 is given describing pairs i.e. people that are partner of each other. C[i][0] and C[i][1] are partner of each other.

Find the minimum number of swaps required to arrange these pairs such that all pairs become adjacent to each other.



Problem Constraints
1 <= A <= 20

1 <= B[i] <= 2A

C[i][0]!=C[i][1]

1 <= C[i][0], C[i][1] <= 2A



Input Format
The First argument given is an integer A.

The Second argument given is the integer array B.

The Third argument given is matrix C.



Output Format
Return the minimum number of swaps required to arrange these pairs such that all pairs become adjacent to each other.



Example Input
Input 1:

A = 3
B = [3, 5, 6, 4, 1, 2]
C = [   [1, 3]
        [2, 6]
        [4, 5]  ]
Input 2:

A = 1
B = [1, 2]
C = [ [1, 2] ]


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

One of the ways to arraange them 
1. swap(5 and 6) order becomes : [3, 6, 5, 4, 1, 2]
2. swap(6 and 1) order becomes:  [3, 1, 5, 4, 6, 2]
Explanation 2:

No swaps required
*/

int ans;

int check(vector<vector<int> > C, vector<int> B){
    int cnt = 0;
    int index[B.size()] = {0};
    for (int i = 0; i < B.size(); ++i)
        index[B[i]] = i;
    
    for (vector<int> x: C){
        int firstIndex = index[x[0]];
        int secondIndex = index[x[1]];
        if (abs(firstIndex-secondIndex) == 1){
            cnt += 2;
        }
    }
    
    return (cnt == B.size());
}

void recurse(int A, vector<int> &B, 
    vector<vector<int>> &C, int currSwap, int currIndex){
        
    if (check(C, B)){
        ans = min(ans, currSwap);
        return;
    }
    
    int index[B.size()] = {0};
    for (int i = 0; i < B.size(); ++i)
        index[B[i]] = i;
    
    for (int i = currIndex; i < C.size(); ++i){
        int firstIndex = index[C[i][0]];
        int secondIndex = index[C[i][1]];
        if (abs(firstIndex-secondIndex) == 1)
            continue;
        
        if (firstIndex+1 < B.size()){
            swap(B[secondIndex], B[firstIndex+1]);
            recurse(A, B, C, currSwap+1, currIndex+1);
            swap(B[secondIndex], B[firstIndex+1]);
        }
        
        if (secondIndex+1 < B.size()){
            swap(B[firstIndex], B[secondIndex+1]);
            recurse(A, B, C, currSwap+1, currIndex+1);
            swap(B[firstIndex], B[secondIndex+1]);
        }
        
        if (firstIndex-1 >= 0){
            swap(B[firstIndex-1], B[secondIndex]);
            recurse(A, B, C, currSwap+1, currIndex+1);
            swap(B[firstIndex-1], B[secondIndex]);
        }
        
        if (secondIndex-1 >= 0){
            swap(B[secondIndex-1], B[firstIndex]);
            recurse(A, B, C, currSwap+1, currIndex+1);
            swap(B[secondIndex-1], B[firstIndex]);
        }
    }
}

int Solution::solve(int A, vector<int> &B, vector<vector<int> > &C) {
    
    ans = INT_MAX;
    recurse(A, B, C, 0, 0);
    
    return ans;
}


vector<int> ans;

void backtrack(int A, int &num) {
    if (A == 0){
        ans.push_back(num);
        return;
    }
    
    backtrack(A-1, num);
    num = num ^ (1<<(A-1));
    backtrack(A-1, num);
}

vector<int> Solution::grayCode(int A) {
    
    int num = 0;
    backtrack(A, num);
    
    return ans;
}
