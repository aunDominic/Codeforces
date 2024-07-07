// #define NDBEUG
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
#include <numeric>
#include <string.h>
#include <random>
#include <cassert>
#include <iomanip>
#include <ios>
#include <map>
#include <climits>
using namespace std;

int rect (int n, int m){
    int ans = INT_MAX;
    if (n == m) return 0;
    if (n == 1) return m-1;
    if (m == 1) return n-1;
    for (int i = 1; i < n; i++){
        // try cutting all possible combinations
        // cut the rectangle 
        // n = 8
        // 1 2 3 4 5 6 7 8 
        // i 
        int temp = rect(i,m);
        int temp2 = rect(n - i, m);
        ans = min(ans, temp + temp2 + 1);
    }
    for (int j = 1; j < m; j++){
        int temp = rect(n, j); 
        int temp2 =rect(n, m -j);
        ans = min (ans, temp + temp2 + 1);
    }
    return ans;
}

int main(){
    // not dp 
    int n,m;
    cin >> n >> m;
    int ans = 0;
    // cout << rect(n,m) << "\n";
    // while (!(n == 1 && m == 1)){
    //     if (n > m){
    //         n -= m;
    //     } else if (n < m){
    //         m -= n;
    //     } else {
    //         break;
    //     }
    //     ans++;
    // }
    // cout << ans;

    // let dp[i][j] denote the min moves require to cut a rectangle of width i and length j into squares
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    for (int i = 1; i <= min(n,m); i++){
        dp[i][i] = 0; // dp[i][i] is already a square
    }


    // dp should be symmetric
    // dp[i][j] = dp[j][i]
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            // need to try cutting all possible locations
            // some cuts should be redundant
            for (int k = 1; k < i; k++){
                
                // cut the rect(i,j) into 
                // rect(k, j) + rect (i - k, j)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);    
            }
            for (int k = 1; k < j; k++){
                dp[i][j] =  min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout << dp[n][m];
    
}