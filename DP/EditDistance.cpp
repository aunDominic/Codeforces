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

int main (){
 
    string s;
    string q;
    cin >> s >> q;

    int n = s.size();
    int m = q.size(); 
    s = " " + s;
    q = " " + q;
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    // let dp[i][j] = min number of moves it takes for 
    // first the i chars of s == the first j chars of q
    // "ababa" "arara"
    // "baba" "rara" -> "aba" "rara" -> 
    //               -> "baba" "ara" 
    // ldist (a: s) (b: q)
    //  | a == b = ldist s q
    //  | otherwise 1 + min (
    //    ldist s (b : q) -> delete a
    //    l dist (a: s) (q) -> 
    //)   l dist s q 
    // 

    for (int i = 0;i <= n; i++){
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++){
        dp[0][j] = j;
    }
    // dp[i][j] 
    // i denotes the first i chars of string s
    // j denotes the first j chars of string q
    // dp[i][j] denotes the min number of moves to transform first i chars to first j chars 
    for (int i = 1;i <= n; i++){
        for (int j = 1; j <= m; j++){
            int cost; 
            if (s[i] == q[j]){
                cost = 0;
            } else cost = 1;
            dp[i][j] = min({
                dp[i-1][j] + 1, // use the first i-1 chars then
                dp[i][j-1] + 1, // insert char i 
                dp[i-1][j-1] + cost // replace char i with char j
            });
        }
    }
    cout << dp[n][m];
    
}