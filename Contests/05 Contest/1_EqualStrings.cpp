int Solution::solve(string A, string B) {
    int countA[256] {0}, countB[256] {0};
    
    for (int i = 0; i < A.length(); i++){
        countA[A[i]]++;
        countB[B[i]]++;
        }   
        
    for (int i = 0; i < 256; i++){
        if ((countA[i]+countB[i])&1){
            return 0;
        }
    }
          
    return 1;    
}
