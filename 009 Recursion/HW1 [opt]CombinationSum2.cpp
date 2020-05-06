/*
Combination Sum II
Problem Description
Given an array of size N of candidate numbers A and a target number B. 
Return all unique combinations in A where the candidate numbers sums to B.  
Each number in A may only be used once in the combination. 

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

Warning: DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS. Example : itertools.combinations in python.
If you do, we will disqualify your submission and give you penalty points.    


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
 
 vector<vector<int>> ans; 
void recurse(vector<int> &A, int B, vector<int> curr, int sum, int index){
    if (sum == B){
        ans.push_back(curr);
        return;
    }
    if (sum > B)
        return;
        
    for (int i = index; i < A.size(); ++i){           // to understand this loop refer EOF 
        curr.push_back(A[i]);
        recurse(A, B, curr, sum+A[i], i+1);
        curr.pop_back();
    }
    return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    ans.clear();
    vector<int> curr;
    sort(A.begin(), A.end());
    recurse(A, B, curr, 0, 0);
    
    set<vector<int>> temp (ans.begin(), ans.end());
    vector<vector<int>> res(temp.begin(), temp.end());
    
    return res;
    
}


/*
FOR LOOP WORKING:
`````````````````

If A = [1,3,5,6]

Then when 
index is 0 --> it includes 0th ele and the next elements like 3,5 & 6 
index is 1 --> it includes 1th ele and the next elements like 5 & 6 
index is 0 --> it includes 2nd ele and the next element 6 

*/
