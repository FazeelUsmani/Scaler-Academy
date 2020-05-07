/*
Kth Smallest Triplet Sum

Problem Description
Given an integer array A of size N. If we store the sum of each triplet of the array A in a new list then
find the Bth smallest element among the list. NOTE: A triplet consist of three elements from the array.
Let's say if A[i], A[j], A[k] are the elements of the triplet then i < j < k.        


Problem Constraints
3 <= N <= 500
1 <= A[i] <= 108
1 <= B <= (N*(N-1)*(N-2))/6


Input Format
First argument is an integer array A.
Second argument is an integer B.


Output Format
Return an integer denoting the Bth element of the list.


Example Input
Input 1:
 A = [2, 4, 3, 2]
 B = 3
Input 2:
 A = [1, 5, 7, 3, 2]
 B = 9
    


Example Output
Output 1:
 9 
Output 2: 
 14 
   


Example Explanation
Explanation 1:
 All the triplets of the array A are:
 (2, 4, 3) = 9
 (2, 4, 2) = 8
 (2, 3, 2) = 7
 (4, 3, 2) = 9
So the 3rd smallest element is 9.
*/

int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    vector<int> v;
    
    for (int i = 0; i < n-2; i++){
        for (int j = i+1; j < n-1; j++){
            for (int k = j+1; k < n; k++){
                int currSum = A[i]+A[j]+A[k];
                v.push_back(currSum);
            }
        }
    }
    sort(v.begin(), v.end());
    
    return v[B-1];
    
}
