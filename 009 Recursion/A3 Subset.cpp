/*
Subset

Problem Description
Given a set of distinct integers, S, return all possible subsets. NOTE:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.


Problem Constraints
1 <= |S| <= 16
INTMIN <= S[i] <= INTMAX


Input Format
First and only argument of input contains a single integer array S.


Output Format
Return a vector of vectors denoting the answer.


Example Input
 S = [1, 2, 3]


Example Output
[
 []
 [1]
 [1, 2]
 [1, 2, 3]
 [1, 3]
 [2]
 [2, 3]
 [3]
]


Example Explanation
You can see that these are all possible subsets.
*/

vector<vector<int>> ans;

void generateSubsets(vector<int> A, int index, vector<int> &curr, bool left){
 
    if (left)
        ans.push_back(curr);
        
    if (index == A.size())
        return;
        
    curr.push_back(A[index]);
    generateSubsets(A, index+1, curr, true);
    curr.pop_back();
    generateSubsets(A, index+1, curr, false);
    
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    ans.clear();
    vector<int> curr;
    sort(A.begin(), A.end());
    generateSubsets(A, 0, curr, true);
    
    return ans;
}
