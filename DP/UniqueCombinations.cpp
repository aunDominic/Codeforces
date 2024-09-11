#include "bits/stdc++.h"
#include <iostream>
using namespace std;

void print_vec(vector<int> &v){
    for (auto a : v){
        cout << a << " ";
    }
    cout << "\n";
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // dp[n][x] be the unique combinations that sum to x, using the first n numbers 
    // dp[i][j] = dp[i-1][j] ie we use the unique combinations found with i-1 
    // else if we use the ith coin, dp[i][j] += dp[i-1][j - coin[i]] given that all these previous ones are unique combinations
    sort(candidates.begin(), candidates.end());
    vector<pair<int,int>> mult;
    int cnt = 1;
    for (int i = 0; i < candidates.size(); i++){
        if (i + 1 < candidates.size() && candidates[i] != candidates[i+1] || i == candidates.size()-1) {
            mult.push_back({candidates[i], cnt});
            cnt = 1;
        } else {
            cnt++;
        }
    }  
    int n = mult.size();

    vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(target+1, vector<vector<int>>()));
    
    // Each number will indeed be used once.
    // Problem arises when there are duplicate numbers in candidates.
    // 
    dp[0][0] = {{}}; 
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= target; j++){
            for (auto v: dp[i-1][j])
                dp[i][j].push_back(v); 
            for (int k = 1; k <= mult[i-1].second; k++){
                if (j - mult[i-1].first * k >= 0) {
            
                    for (auto v : dp[i-1][j - mult[i-1].first * k]){
                        vector<int> tmp = v;
                        for (int kk = 0; kk < k; kk++){
                            tmp.push_back(mult[i-1].first);
                        }
                        dp[i][j].push_back(tmp);
                    }
                }
            }           
            
        }
    }
    
    
    return dp[n][target];
}

int main(){
    vector<int> v = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(v, target);
    for (auto v: ans)
        print_vec(v);
}