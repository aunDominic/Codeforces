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
    int n, x;
    cin >> n >> x;

    vector<int> v(n,0);
    for (int i = 0; i< n ;i ++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<pair<int,int>> dp(pow(2,n), {INT_MAX, INT_MAX});
    // let dp[i] denote (minimum number of elevator rides, minimum used capacity on the last elevator ride) 
    // from transport the ith subset of people;
    dp[0] = {1,0};
    for (int i = 1; i < pow(2,n); i++){
        for (int mask = 1; mask <= i; mask = mask << 1){
            if (i & mask){
                int rides = dp[i-mask].first;
                int used = dp[i-mask].second;
                int index = log2(mask);
                if (v[index] + used <= x){
                    used += v[index];
                } else {
                    rides++;
                    used = v[index];
                }
                dp[i] = min(dp[i], {rides,used});
            }
        }
    }  
    cout << dp[pow(2,n) - 1].first;
}