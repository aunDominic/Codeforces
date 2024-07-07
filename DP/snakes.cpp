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

int main(){
    freopen("snakes.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("snakes.out", "w", stdout);
    int n, k; 
    cin >> n >> k;
    vector<int> v(n+1,0);
    k++;
    for (int i = 0; i < n; i++){
        cin >> v[i+1];
    }
    vector<vector<long long>> dp(k+1, vector<long long>(n+1, LLONG_MAX));
    // let dp[k][n] denote the min wasted space 
    // by dividing n into k groups;
    // min wasted space = max of group * size of group - sum of group
    // dp[k][n] = min for all j . (dp[k-1][j] + min wasted space of group [j+1 .. n])
    vector<int> p(n+1,0);
    for (int i = 1; i <= n; i++){
        p[i] = p[i-1] + v[i];
    }
    
    vector<vector<int>> rmq(n+1, vector<int>(n+1, 0));
    for (int l = 1; l <= n; l++){
        for (int r = l; r <= n; r++){
            if (l == r) {
                rmq[l][r] = v[l];
                continue;
            }
            rmq[l][r] = max(v[r], rmq[l][r-1]);
        }
    }
    for (int i = 1; i <= n; i++){
        dp[1][i] = rmq[1][i] * i - (p[i] - p[0]);
    }
    for (int i = 2; i <= k; i++){
        for (int j = 0; j <= n; j++){
            if (i >= j) {
                dp[i][j] = 0;
                continue;
            }
            for (int m = 1; m < j; m++){
                // maxx in [m+1, j]
                dp[i][j] = min(dp[i][j], dp[i-1][m] + rmq[m+1][j] * (j - m) - (p[j] - p[m]));
            }
        }
    }
    cout << dp[k][n];

    


}