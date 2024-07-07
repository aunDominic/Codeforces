// LUOGU_RID: 110352149
// Author:dd
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("avx2")
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

struct Box{
    long long h,p;
    Box (long long h, long long p):
        h(h), p(p){}
};
bool cmp (const Box &a, const Box &b){
    return b.h + b.p > a.h + a.p;
}

int main () {
    int n;
    cin >> n; 
    vector<Box> v;
    
    for (int i = 0 ; i < n; i++){
        long long h,p;
        cin >> h >> p;
        v.push_back(Box(h,p));
    }
    sort(v.begin(), v.end(), cmp);

    vector<vector<long long>> dp(n+1, vector<long long>(n+1,LLONG_MAX));
    // let dp[i][j] denote the minimum weight of a tower
    // made from a subset from the first i boxes
    // using exactly j boxes?

    // dp[i][j] = min dp[i-1][j-1]
    dp[0][0] = 0;
    for (int j = 0; j <= n; j++){
        dp[j][0] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            dp[i][j] = dp[i-1][j];
            if (v[i-1].h >= dp[i-1][j-1]){
                 dp[i][j] = min(dp[i][j], dp[i-1][j-1] + v[i-1].p);
            }
            if(dp[i][j] != LLONG_MAX) ans = max(ans, j);
        }
    }   
    cout << ans;

}