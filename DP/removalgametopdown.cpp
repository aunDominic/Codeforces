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
int n ;
int N = 5000;
vector<vector<long long>> dp(N, vector<long long>(N,0));
vector<vector<bool>> visited(N, vector<bool>(N, false));
long long remove(int l, int r, vector<long long> &v, bool p){
    if (l > r) return 0;
    visited[l][r] = true;
    long long left;
    if (l+1 < n && visited[l+1][r]) left = dp[l+1][r];
    else {
        left = remove(l + 1, r, v, !p);
    }
    long long right;
    if (r - 1 >= 0 && visited[l][r-1]){
        right = dp[l][r-1];
    } else {
        right = remove(l, r - 1,v, !p);
    }
    if (p) {
        long long res = max(left + v[l], right + v[r]);
        dp[l][r] = res;
        return res;
    } else {
        long long res = min(left, right);
        dp[l][r] = res;
        return res;
    }
}
 
int main (){
    cin >> n;
    vector<long long> v(n,0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long ans = remove(0, n - 1, v, true);
    cout << ans << "\n"; 
 
    // let dp[l][r][p] denote the maximum score obtained starting from player p
    // when selecting from items in the range [l,r]
    // dp[0][n-1][0] is the answer.
    // dp[l][r] is transitioned from:
    // 1. dp[l+1][r][p]
    // 2. dp[l][r-1][p]
    vector<vector<long long>> dp(n, vector<long long>(n,0));
 
 
}