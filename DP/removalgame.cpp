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
 
int remove(int l, int r, vector<int> &v, bool p){
    if (l > r) return 0;
    int left = remove(l + 1, r, v, !p);
    int right = remove(l, r - 1,v, !p);
    if (p) {
        return max(left + v[l], right + v[r]);
    } else {
        return min(left, right);
    }
}
 
int main (){
    int n;
    cin >> n;
    vector<long long> v(n,0);
    int sum = 0 ;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    // cout << remove(0, n - 1, v, true) << "\n"; 
 
    // let dp[l][r] denote the difference in score 1 - score2
    // using elements in the array [l,r] and player 1 starts
    // if player 1 chooses l, then player2 will try to minimise [l+1, r]
    // if player 1 choose r, then player2 will try to minimise [l, r-1]

    vector<vector<long long>> dp(n, vector<long long> (n, 0));
    for (int i = 0; i < n; i++){
        dp[i][i] = v[i];
    }
    for (int l = n-1; l >= 0; l--){
        for (int r = l; r < n; r++){    
            if (l == r) continue;
            dp[l][r] = max(v[l] - dp[l+1][r], v[r] - dp[l][r-1]);
        }
    }
    cout << (sum + dp[0][n-1]) /2;
}
