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
int gcd (int a, int b) {
    if (b == 0)
    return a;
    else
    return gcd (b, a % b);
}





int main(){
    int t;
    cin >> t;
    // wtf
    // how does this work
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid (n, vector<int>(m,1));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m;j++){
                cin >> grid[i][j];
            }
        }
        vector<vector<set<int>>> dp;
       for (int i = 0; i < n; i++){
            vector<set<int>> tmp;
            for (int j = 0; j < m; j++){
                set<int> tmpp;
                tmp.push_back(tmpp);
            }
            dp.push_back(tmp);

       }
        dp[0][0] = {grid[0][0]};
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (i > 0){
                    for (auto k : dp[i-1][j]){
                        // invariant
                        // the size of dp[i][j] is kept to the number of composite numbers???
                        // wtf is the bounds on the size
                        int tmp = gcd(k, grid[i][j]);
                        dp[i][j].insert(tmp);
                        for (auto kk : dp[i][j]){
                            if (kk != tmp && kk % tmp == 0){
                                dp[i][j].erase(tmp);
                                break;
                            }
                        }
                    }
                }
                if (j > 0){
                    for (auto k: dp[i][j-1]){
                        int tmp = gcd(k, grid[i][j]);
                        dp[i][j].insert(tmp);
                        for (auto kk: dp[i][j]){
                            if (kk != tmp && kk % tmp == 0){
                                dp[i][j].erase(tmp);
                                break;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (auto k: dp[n-1][m-1]){
            ans = max(ans, k);
        }
        cout << ans << "\n";
        

    }
  
}