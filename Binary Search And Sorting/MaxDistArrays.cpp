#include "bits/stdc++.h" 
using namespace std;   
int maxDistance(vector<vector<int>>& arrays) {
    // the max distance must be the min element of one of the array
    // and the max element of another array
    // both arrays must be distinct 
    // but we're taking an absolute value??
    // if a and b different signs, its better if b is negative and a positive or b positive and a negative
    // since we get to choose a and b, it doesnt matter if let a or b negative, so WLOG let (a,b) be such that |a| > |b|
    // otherwise if both are the same sign
    // is better if |a| > |b| 


    // the answer is a tuple(a,b) where a is max and b is min from two different arrays
    // [-5,0,5] [1,2,3] -> (-5, 3)
    // a should be as close to +inf
    // b should as close to -inf 
    // if both a and b are in the same array, then how?
    // let (a_i, b_i) be these start and end of each array 
    // we have to pick 
    
    set<pair<int,int>> left;
    set<pair<int,int>> right;
    int n = arrays.size();
    for (int i = 0; i < n; i++){  
        left.insert({arrays[i][0], i});
        right.insert({arrays[i].back(), i});
    }
    int ans = 0;
    for (auto &[l, i] : left){
        int r = arrays[i].back();
        auto it = right.find({r, i});
        right.erase(it);
        auto [maxr, j] = *right.rbegin();
        ans = max(ans, abs(l - maxr));
        right.insert({r, i});
    }
    return ans;
}
    