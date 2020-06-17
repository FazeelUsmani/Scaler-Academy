long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
long long fact[1000005];
int Solution::solve(int A, int B, int C) {
    
    fact[0]=1;
    for(long long i=1;i<=A;++i){
        fact[i]=(fact[i-1]*i)%C;
    }
    
    long long ans = fact[A];
    ans = ( ans * binpow(fact[B],C-2,C))%C;
    ans = ( ans * binpow(fact[A-B],C-2,C))%C;
    
    return ans;
}
