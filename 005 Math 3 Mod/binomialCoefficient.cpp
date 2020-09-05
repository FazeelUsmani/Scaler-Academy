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
