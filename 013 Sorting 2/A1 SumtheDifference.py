Sum the Difference
Problem Description
Given an integer array A of size N. You have to find all possible non-empty subsequence of the array of numbers and then, for each subsequence, find the difference between the largest and smallest numbers in that subsequence Then add up all the differences to get the number. As the number may be large, output the number modulo 1e9 + 7 (1000000007). NOTE: Subsequence can be non-contiguous. 


Problem Constraints
1 <= N <= 10000 1<= A[i] <=1000 


Input Format
First argument is an integer array A.


Output Format
Return an integer denoting the output.


Example Input
A = [1, 2]


Example Output
1


Example Explanation
All subsets
[1]    largest-smallest = 1 - 1 = 0
[2]    largest-smallest = 2 - 2 = 0
[1 2]  largest-smallest = 2 - 1 = 1
Sum of the differences = 0 + 0 + 1 = 1
So resultant number is 1



int Solution::solve(vector<int> &A) {
    
    long long _max = 0, _min = 0;
    sort(A.begin(), A.end());
    
    int n = A.size();
    if (n < 2)
        return 0;
    
    for (int j = 0; j < n; j++){
        _min = (_min * 2)% 1000000007;
        _min = (_min + A[j]) % 1000000007;
    }    
    
    for (int i = n-1; i >= 0; i--){
        _max = (_max * 2) % 1000000007;
        _max = (_max + A[i]) % 1000000007;
    
    }

    
    long long ans = (_max - _min + 1000000007) % 1000000007;
                                   
    
    return ans;
    
}
