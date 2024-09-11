#include "bits/stdc++.h"
#include <iostream>
using namespace std;

const int N = 5;
long long mag(pair<long long, long long> a, pair<long long, long long> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
long long dp[N][N][2];
int main(){
    int n,m; 
    cin >> n >> m;

    // let dp[i][j][0] be the minimum energy used to perform a tour thru Holstein cows and Guernsneys cows in order of i and j ending with an i cow
    // the dp[i][j] either comes from dp[i-1][j] or dp[i][j-1]
    // for fixed j, to reach cow i, we must have reach all cows 1 .. i-1
    // which cow did i end on? i cant end on any cow 1..i-2, if i did, => i never got thru cow i-1
    // by similar logic, i also cant end on any cow 1..j-,so i either ended on cow i-1 or cow j-1

    // if i came from dp[i-1][j], i must have ended on either i-1 or j, the min answer chosen could be from either of these 
    vector<pair<long long,long long>> h(n+1,{0,0});
    vector<pair<long long,long long>> g(m+1,{0,0});
    for (int i = 1; i <= n; i++){
        int a,b; cin >> a >> b;
        h[i] = {a,b};
    }
    for (int i = 1; i <= m; i++){
        int a,b; cin >> a >> b;
        g[i] = {a,b};
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            
            dp[i][j][0] = min({
                dp[i-1][j][0] + (mag(h[i], h[i-1])),
                dp[i][j-1][1] + (mag(h[i], g[i-1])),
            });
            dp[i][j][1] = min({
                dp[i-1][j][0] + (mag(g[i], h[i-1])),
                dp[i][j-1][1] + (mag(g[i], g[i-1])),
            });
        }
    }
    cout << dp[n][m][0];
}