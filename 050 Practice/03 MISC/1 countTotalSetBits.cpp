int kerninghan(int n){
    int cnt = 0;
    while (n > 0){
        n = (n & (n-1) );
        cnt++;
    }
    return cnt;
}

int Solution::solve(int A) {
    int ans = 0;
    
    for (int i = 1; i <= A; ++i){
        ans += kerninghan(i);
    }
    return ans;
}
