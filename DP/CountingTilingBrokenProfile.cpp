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

const int MOD = 1e9+ 7;

int main(){

    int n, m; 
    cin >> n >> m;

    // dp[i][j][mask] = number of ways to tile the grid
    // where counting from col by col, then row by row
    // all cells from (0,0) to (i, j-1) are tiled
    // all cells from (i+1, j) to (N-1, M-1) are not tiled
    // There are then N cells remainng
    // masks = bk.bk-1...b2.b1, 
    // where the kth bit represents the cell on the kth row is set. 
    // cell[k][j] = 1 represents it being empty. 

    // Transitions 
    // if cell[i][j] is tiled, 
    //      then we can either place a horizontal to the left: dp[i-1][j][mask xor 2^i]
    //      or vertical to the top: dp[i-1][j][mask xor 2^i-1]
    // if cell[i][j] is not tiled
    //      then cell[i][j-1] is tiled: dp[i-1][j][mask xor 2^i]

    // in every transition, we only need dp[i-1][j][mask] to answer this
    // so we only need to keep track of the previous state. 
    // so let dp[i-1][j][mask] = dp[mask][0]
    // dp[i][j][mask] = dp[mask][1]
    vector<vector<int>>dp(1 << n, vector<int>(2, 0));

    dp[0][0] = 1;
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            for (int mask = (1 << n) - 1; mask >= 0; mask--){
                dp[mask][1] = dp[mask ^ (1 << i)][0]; // horizontal or tiled
                if (i && !(mask & (1 << i)) &&
				    !(mask & (1 << i - 1))) { // vertical
                     dp[mask][1] += dp[mask ^ (1 << (i-1))][0];
                } 
                if (dp[mask][1] >= MOD) dp[mask][1] -= MOD;

            }
            for (int mask = 0; mask < (1 << n); mask++)
				dp[mask][0] = dp[mask][1];
        }
    }
    cout << dp[0][0];
}