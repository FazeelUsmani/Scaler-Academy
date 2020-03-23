Aggressive cows
Problem Description
Farmer John has built a new long barn, with N stalls. Given an array of integers A of size N where each element of the array represents the location of the stall, and an integer B which represent the number of cows. His cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, John wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?  


Problem Constraints
2 <= N <= 100000
0 <= A[i] <= 109
2 <= B <= N


Input Format
The first argument given is the integer array A.
The second argument given is the integer B.


Output Format
Return the largest minimum distance possible among the cows.


Example Input
 A = [1, 2, 3, 4, 5]
 B = 3


Example Output
 2


Example Explanation
 John can assign the stalls at location 1,3 and 5 to the 3 cows respectively.
 So the minimum distance will be 2
 
 

#define ll long long



bool allocate(vector<int> &A, int C, int mid, int n);

bool allocate(vector<int> &A, int C, int mid, int n){
    C--;
    int sum = 0;
    int i = 1;
    
    while ((C!=0) && (i<n)){
        sum += A[i] - A[i-1];
        if (sum  >= mid){
            C -= 1;
            sum = 0;
        }
        i++;
    }
    if (C!=0)
        return false;
        
    return true;
}

int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    sort(A.begin(), A.end());
    int low = 0, high = A[n-1]+1, mid;
    
    while ((high-low)>1){
        mid = low + (high-low)/2;
        
        if (allocate(A, B, mid, n))
            low = mid;
        else
            high = mid;
    }
    return low;
}
