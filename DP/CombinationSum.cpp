#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // target = 40, 
        // Let dp[i][j] = a list of combination of numbers such that its sum is equal to j
        // using only the first i numbers
        int n = candidates.size();
        int x = target;
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(x+1, vector<vector<int>>()));
        dp[0][0] = {{}}; // the empty list ie no numbers required to sum to zero
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= x; j++){
                dp[i][j] = dp[i-1][j];
                if (j - candidates[i-1] >= 0) {
                    vector<vector<int>> v = dp[i][j - candidates[i-1]];

                    for(int k = 0; k < v.size(); k++){
                        v[k].push_back(candidates[i-1]);
                        dp[i][j].push_back(v[k]);
                    }
                }
            }
        }
        return dp[n][x];

    }
};

int main(){
    Solution sol;
    vector<int> v = {2,3,6,7};
    sol.combinationSum(v, 7);

}