/*

Distribute Candy

Problem Description

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?



Problem Constraints
1 <= N <= 105
-109 <= A[i] <= 109



Input Format
First and only argument is an integer array A representing the rating of children.



Output Format
Return an integer, representing the minimum candies to be given.



Example Input
Input 1:

 A = [1, 2]
Input 2:

 A = [1, 5, 2, 1]


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 The candidate with 1 rating gets 1 candy and candidate with rating 2 cannot get 1 candy as 1 is its neighbor. 
 So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.
Explanation 2:

 Candies given = [1, 3, 2, 1]

*/

int Solution::candy(vector<int> &A) {
    
    int n = A.size();
    vector<int> left (n, 1);
    vector<int> right (n, 1);
    
    for (int i = 1; i < n; i++){
        if (A[i] > A[i-1]){
            left[i] = left[i-1]+1;
        }
        else
            left[i] = 1;
    }
    
    for (int j = n-2; j >= 0; j--){
        if (A[j] > A[j+1]){
            right[j] = right[j+1]+1;
        }
        else
            right[j] = 1;
    }
    
    int candies = 0;
    for (int i = 0; i < n; i++){
        candies += max(left[i], right[i]);
    }
        
    return candies;
}   
