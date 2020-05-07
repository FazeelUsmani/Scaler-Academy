/*
XOR Prime
Problem Description
Given an array A of integers of size N. For each integer in A, there is a set S of the prime factors of that integer. 
There is a good value associated with each number, which is the sum of XOR of all subsets of set S modulo 109+7.
Good Value of the array A is the sum of good values associated with each number modulo 109+7. 
Return Good Value of A.  Note: Set S has no duplicates.         


Problem Constraints
1 <= N <= 1000 1 <= A[i] <= 109 


Input Format
Single argument is an integer.


Output Format
Return the Good Value of A.


Example Input
Input 1:
 A = [10, 45]
 Input 2:
 A = [3, 7] 
 


Example Output
Output 1:
 28
 Output 2:
 10 
 


Example Explanation
Explanation 1:
Prime factors of 10 are 2, 5. Subsets of {2,5} are {},{2},{5},{2,5}. Their corresponding xors are 0,2,5,7.
Their sum is 0+2+5+7 = 14.  So, good value of 10 is 14.
Prime factors of 45 are 3, 5. Subsets of {3,5} are {},{3},{5},{3,5}. Their corresponding xors are 0,3,5,6.
Their sum is 0+3+5+6 = 14.  So, good value of 45 is 14.

Good Value of array = 14 + 14 = 28.
*/


/*

Step 1: Generate prime factors from 2 to 10^5 using Sieve in Nxlog N time (feasable)
        primeArr = [2,3,5,7,11...] no more than O(10^3)
        
        For {2,5} we have 2^len({2,5}) subsets i.e. 4
        
Step 2: Generate All Subarrays
Step 3: Take sum of XOR of all subsets
Step 4: Add ans of step 3 to final ans

*/




int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    int prime[100005];
    memset(prime, true, 100000);
    
    vector <int> primeNo;
    for (int i = 2; i * i <= 100000; i++){
        if (prime[i]){
            primeNo.push_back(i);
            for (int j = i*i; j <= 100000; j+=i){
                prime[j] = false;
            }
        }
    }
    
    int sol = 0;
    for (int i = 0; i < n; ++i){
        
        int item = A[i];
        vector<int> primeFac;
        int j = 0; 
        while (j < primeNo.size()){
            if (item % primeNo[j] == 0){
                primeFac.push_back(primeNo[j]);
                while (item % primeNo[j] == 0){
                    item = item/primeNo[j];
                }
                if (item == 1)
                    break;
            }
            j++;
        }
        
        if (item != 1)
            primeFac.push_back(item);
            
        int good_value = 0;
        int nof = primeFac.size();
        
        for (int i = 0; i < (1 << nof); ++i){
            int temp = 0;
            for (int j = 0; j < nof; ++j){
                if (i & (1<<j))
                    temp = temp ^ primeFac[j];
            }
            good_value = (good_value + temp) % 1000000007; 
        }
        sol = sol + (good_value) % 1000000007;
    }
    
    return sol;
}
