int Solution::solve(int A) {
    int ans = 0;
    for(int i = 1; i <= A/2; i++){
        if((A-i) % i == 0){
            ans++;
        }
    }
    return ans;
}
