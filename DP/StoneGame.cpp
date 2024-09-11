#include "bits/stdc++.h"
#include <iostream>
using namespace std;
const int M = 4;
const int X = 6;
const int NUMPLAYERS = 2;
int stoneGameII(vector<int>& piles) {
    vector<vector<vector<int>>> dp(M+1, vector<vector<int>>(X+1, vector<int>(NUMPLAYERS, 0)));

    // 2 -> 4 -> 8
    // use prefix sum to calculate how much a move can get you? 
    // straight up dp
    // max of m is 64
    // let dp[x][m][2] be the max number of stones alice can get if played optimally
    // where m is taking up to m piles , x is number of piles taken, 0 -> alice turn, 1 -> bobs turn
    dp[0][1][0] = 0; // no piles taken
    dp[0][1][1] = 0;
    int x = piles.size();
    vector<int> psum(x+1,0);
    for (int i = 1; i <= x; i++){
        psum[i] += psum[i-1] + piles[i-1];
    }
    // dp[i][j - i]
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= i; j++){ // you can only take j piles from the states where >= j / 2 
            
            dp[i][j][0] = max(dp[i][j][0], dp[i-j][j][1] + psum[i] - psum[i - j]);
            dp[i][j][1] = min(dp[i][j][1], dp[i-j][j][0] - (psum[i] - psum[i - j]));
        
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= M; j++){
        ans = max(dp[x][j][0], ans);
    }
    ans += psum[x];
    ans /= 2;
    return ans;
}
int main (){
    vector<int> piles = {1,2,3,4,5,100};
    cout << stoneGameII(piles);
}