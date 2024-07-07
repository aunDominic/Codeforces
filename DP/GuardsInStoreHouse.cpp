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

int main (){
    int n, m;
    cin >> n >> m;
    
    // x.x
    // .x. 
    // 
    // 

    vector<vector<char>> grid(n, vector<char>(m, 'a'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
       }
    }

    // let dp[i][j][mask] = the number of ways to have an assignment of guards such that no more than 1 cell is unguarded
    // cells (0,0) to cell (i, j-1) are protected frs 
    // and cells (i+1, j) to cell (n-1,m-1) are not protected 
    // masks represent a possible configuration of cells between (i+1, j-1) to (i, j)
    // cell(i,j) is not a block
    // if the ith bit of the mask is 0, cell(i,j) is protected 
    //  case 1: atleast one of cell (0:i-1, j) has a guard
    //          OR cell(i-1, j) is protected and is not a block => that there is a guard along the jth column
    //          dp[i-1][j][mask xor 2^(i-1)] && !cell[i-1][j]
    //               
    //  case 2: atleast one of cells (i, 0:j-1) has a guard
    //          OR cell(i, j-1) is protected and is not a block => that there is a guard along the ith row
    //          dp[i-1][j][mask] && !cell[i][j-1]

    //  case 3: we place a guard on cell i, j 
    //          dp[i-1][j][mask]

    // cell(i,j) is a block 
    // the cell is already protected 
    // dp[i-1][j][mask]

    // go col by col, then row by row
    vector<vector<int>> dp(1 << n, vector<int>(2,0));
    dp[0][0] = 1;
    for (int j = 0; j < m; j++){ // col
        for (int  i = 0; i < n; i++){ // row
            for (int mask = 0; mask < (1 << n); mask++){
                // bit 0 means unprotected
                // bit 1 means protected
                    //  case 1: atleast one of cell (0:i-1, j) has a guard
                    //          OR cell(i-1, j) is protected and is not a block => that there is a guard along the jth column
                    //          dp[i-1][j][mask xor 2^(i-1)] && !cell[i-1][j]
                    //               
                    //  case 2: atleast one of cells (i, 0:j-1) has a guard
                    //          OR cell(i, j-1) is protected and is not a block => that there is a guard along the ith row
                    //          dp[i-1][j][mask] && !cell[i][j-1]

                    //  case 3: we place a guard on cell i, j 
                    //          dp[i-1][j][mask]

                    // cell(i,j) is a block 
                    // the cell is already protected 
                    // dp[i-1][j][mask]
                if (mask ^ (1 << i)){
                    if (grid[i][j] == '.'){ // no block
                        // Dont add a guard 
                        if (i > 0  && grid[i-1][j] == '.' && (mask & (1 << (i-1)))) dp[mask][1] += dp[mask][0]; // behind (col) 
                        if (j > 0 && grid[i][j-1] == '.') dp[mask][1] += dp[mask][0]; // at the back (row)
                        // Add a guard
                        dp[mask][1] += dp[mask][0];
                    } else { // if its block, then its already protected
                        dp[mask][1] += dp[mask][0];
                    }
                } else { 
                    dp[mask][1] += dp[mask ^ (1 << i)][0];
                }
                if (dp[mask][1] > MOD) dp[mask][1] -= MOD;
            }
            for (int mask = 0; mask < (1 << n); mask++) dp[mask][0] = dp[mask][1];
        }
    }
    cout << dp[0][0];

    }

    cout << "\n";

}