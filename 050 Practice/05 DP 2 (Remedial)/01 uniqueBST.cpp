int Solution::numTrees(int A) {    
    if (A <= 1)
        return 1;
    
    unsigned long int ans = 0;
    for (int i = 0; i < A; ++i)
        ans += numTrees(i)*numTrees(A-i-1);
    
    return ans;
}
