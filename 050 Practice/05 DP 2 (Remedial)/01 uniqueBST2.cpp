typedef long long ll;

// Binomial Coeefficient C(n, k)
ll binomialCoeff(int n, int k){
    
    ll res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n-k)
        k = n-k;
    
    for (int i = 0; i < k; ++i){
        res *= (n-i);
        res /= (i+1);
    }
    
    return res;
}

int Solution::numTrees(int A) {
    
    // Use below formula to calculate catalan number in O(N) time
    // C_n=\frac{1}{n+1}\binom{2n}{n}
    // ans = [1/(n+1)]*[(2nCn)]
    
    ll c = binomialCoeff(2*A, A);
    
    return c/(A+1);
}
