float evenProb(float p, int n) {
    // Precompute even factorials;
    // fact[i] = (2i)!
    vector<long long> fact(n/2+1, 1);
    for (int i = 1; i < n/2+1; i++){
        fact[i] = fact[i-1] * (i * 2 - 1) * (i * 2);
    }
    double ans = 0;
    for (int i = 0; i <= n; i += 2){
        // Calculate n choose i * p ^ i 
        // and i is the even natural numbers
        // NCi = n! / i! / (n-i)!
        // nCi = nC(n-i)
        ans += pow(1-p, n-i) * pow(p, i) * fact[n/2] / fact[i/2] / fact [(n-i)/2];
    }
    return ans;
    
}