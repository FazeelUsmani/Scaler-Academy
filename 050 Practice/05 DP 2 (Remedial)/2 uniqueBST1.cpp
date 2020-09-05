int Solution::numTrees(int A) {
    
    unsigned long int catalan[A+1];
    catalan[0] = catalan[1] = 1;
    
    for (int i = 2; i <= A; ++i){
        catalan[i] = 0;
        for (int j = 0; j < i; ++j){
            catalan[i] += catalan[j]*catalan[i-j-1];
        }
    }
    
    return catalan[A];
}
