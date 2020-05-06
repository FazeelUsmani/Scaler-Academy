/*
Combination Sum II
Problem Description
Given an array of size N of candidate numbers A and a target number B. Return all unique combinations in A where the candidate numbers sums to B.  Each number in A may only be used once in the combination. Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
 Warning: DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS. Example : itertools.combinations in python. If you do, we will disqualify your submission and give you penalty points.    


Problem Constraints
1 <= N <= 20


Input Format
First argument is an integer array A denoting the collection of candidate numbers.
Second argument is an integer which represents the target number. 


Output Format
Return all unique combinations in A where the candidate numbers sums to B.


Example Input
Input 1:
A = [10, 1, 2, 7, 6, 1, 5]
B = 8
    


Example Output
Output 1:
[ [1 1 6 ]
  [1 2 5 ]
  [1 7 ] 
  [2 6 ] ]
    


Example Explanation
Explanation 1:
 1 + 1 + 6 = 8
 1 + 2 + 5 = 8
 1 + 7 = 8
 2 + 6 = 8
 All the above combinations sum to 8 and are arranged in ascending order.
*/


#include <bits/stdc++.h>
using namespace std;

// Once we decide to ignore num i, skip all the i's in the list
void recurse(vector<int> &A, int B, vector<int> v, vector<vector<int>> &ans, int sum, int index){
    if (sum > B)
        return;
    if (sum == B){
        for (auto x : v)
            cout<<x<<" ";
        cout<<endl;
        ans.push_back(v);
        return;
    }
    if (index >= A.size())
        return;

    recurse(A,B,v,ans,sum, index+1);
    v.push_back(A[index]);
    recurse(A,B,v,ans,sum+A[index], index+1);
    v.pop_back();    

    return;
}

vector<vector<int>> combinationSum(vector<int> &A, int B){
    vector<int> v;
    vector<vector<int>> ans;

    sort (A.begin(), A.end());

    recurse (A, B, v, ans, 0, 0);
    
    vector<vector<int>> temp;
    for (auto x : ans){
        temp.push_back(x);
    }
    
    return temp;
}


int main(){

    vector<int> A{1,1,2,2};
    int B = 4;
    vector<vector<int> > res;
    res = combinationSum(A, B);

    cout<<"Ans is \n";
    set<vector<int>> ans (res.begin(), res.end());
    for (auto x : ans){
        for (int i = 0; i < x.size(); i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
