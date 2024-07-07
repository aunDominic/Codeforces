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

int findSafeWays(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    const long long Mod = 1e9 + 7;
    vector<vector<long long>> dp(n, vector<long long> (m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 0) continue;
            if (i-1 >= 0) {
                dp[i][j] += dp[i-1][j] ;
                dp[i][j] %= Mod;
            }
            if (j-1 >= 0) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= Mod;
            }
            
        }
    }
    return dp[n][m] % Mod;
    
}

int main () {
    vector<vector<int>> grid = {{1,1,1},{1,1,1},{1,1,1}};
    cout << findSafeWays(grid);
}