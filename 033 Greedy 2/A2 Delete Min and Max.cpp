/*

Delete Min and Max

Problem Description

Given an array A, of N numbers, you want to keep only distinct numbers in the array.
To achieve this, you can pick any three numbers, and discard the maximum and minimum of the three, 
and keep the middle one back in the array.

Find the maximum number of distinct numbers in the array that will be left.



Problem Constraints
3 <= N <= 105
N is an odd number.
1 <= A[i] <= 105


Input Format
The first and the only argument of input contains an integer array A, of size N.



Output Format
Return an integer representing the answer.



Example Input
Input 1:

 A = [1, 1, 2]
Input 2:

 A = [1, 1, 2, 2, 2, 3, 1]


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

 You can pick 1, 1, 2. After discarding minimum (1) and maximum (2) from the array, you will have [1] left.
Explanation 2:

 You can pick 2, 2, 2. After discarding minimum (2) and maximum (2) from the array, you will have [1, 1, 2, 3, 1] left.
 You can pick 1, 1, 1. After discarding minimum (1) and maximum (1) from the array, you will have [1, 2, 3] left.
 
*/

int Solution::solve(vector<int> &A) {
    
    unordered_map <int, int> umap;
    
    for (int i = 0; i < A.size(); i++){
        umap[A[i]]++;
    }
    
    int cnt = 0, freq2 = 0;
    for (auto it = umap.begin(); it != umap.end(); it++){
        int x = it->second;
        while (x > 2){
            x -= 2;
        }
        if (x == 1)
            cnt++;
        else
            freq2++;
    }
    
    cnt = cnt+freq2;
    
    if (freq2&1)
        cnt--;
    
    return cnt;
}

