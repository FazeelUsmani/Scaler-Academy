/*

Candies in Box

Problem Description

There are 2 * N small boxes containing candies denoted by an integer array A of size 2 * N.

There are N-1 big boxes and each big box can accomodate exactly 2 small boxes.

So, we can use exactly 2 * (N-1) small boxes.

The cost of each big box is the absolute difference of candies in that box.

For example: A big box contain two small boxes with candies 4 and 6 then the cost of this big box will be | 4 - 6 | = 2.

You have to fill all the big boxes such that the total cost of big boxes are minimized.

Find and return the minimum total cost of big boxes.



Problem Constraints
1 <= N <= 50

1 <= A[i] <= 107



Input Format
First argument is an integer array A of size 2 * N.



Output Format
Return an integer denoting the minimum total cost of big boxes.



Example Input
A = [2, 4, 1, 10, 6, 15]


Example Output
3


Example Explanation
Since 2 * N = 6. So there are 2 big boxes, we can place 4 small boxes inside the 2 big boxes.
Inorder to minimize the cost, we will select boxes with candies (2, 1) and (4, 6). So the minimum cost will be 2 + 1 =3.



*/


int Solution::solve(vector<int> &A) {
    
    sort(A.begin(), A.end());
    int n = A.size();
    int ans = INT_MAX;;
    vector<int> B(n-2);
   
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int b = 0;
            for (int k = 0; k < n; k++){
                if ((i != k) && (j != k)){
                    B[b++] = A[k];
                }
            }
            
            int s = 0;
            for (int k = 0; k < B.size()-1; k+= 2)
                s += B[k+1]-B[k];
                
            ans = min(ans, s);
        }   
    }
        
    return ans;
}
