    #include "bits/stdc++.h"
    #include <iostream>

    using namespace std;
    int minSteps(int n) {
        // min steps to sum to n 
        // 
        // let dp[i][j] be the minimum number of operations to sum to n 
        // where i the current copy and j is the current sum
        // then dp[i][j] = min (for all j . (dp[i-j][j] + 1)) // use paste
        // dp[i][i] is copy 

        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));
        dp[0][0] = 0; // cant have a copy of zero actually
        dp[1][0] = 0; // has a copy of 1 
        for (int i = 1; i <= n; i++){
            // Update sums
            for (int j = 0; j <= i; j++){
                dp[i][j] = min(dp[i][j], dp[i-j][j] + 1);
            }
            // Update copies, ie set copy to sum 
            for (int j = 0; j <= i; j++){
                dp[i][i] = min(dp[i][j] + 1, dp[i][i]);
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= n; i++){
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }

int main(){
    int n = 4;
    cout << minSteps(n);
}