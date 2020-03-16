3 Sum
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. Assume that there will only be one solution 

Example: given array S = {-1 2 1 -4}, and target = 1. 
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)


int Solution::threeSumClosest(vector<int> &A, int B) {
        
    sort(A.begin(), A.end());
    
    int closestSum = INT_MAX - *max_element(A.begin(), A.end()) - 1;
    
    for (int k = 0; k < A.size(); k++){
        
        int i = k+1, j = A.size()-1;
        
        while ( i < j ){
            int sum = A[i] + A[j] + A[k];
            
            if (abs(B - sum) < abs(B - closestSum))
                closestSum = sum;
                
            if (sum > B)
                j--;
            else
                i++;
        }
    }
    
    return closestSum;
}
