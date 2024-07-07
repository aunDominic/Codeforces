vector<int> v(n,0);
    vector<long long> dp(n+1,LLONG_MAX);
    dp[0] = -LLONG_MAX;