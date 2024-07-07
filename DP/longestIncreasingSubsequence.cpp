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
    int n;
    cin >> n;
    vector<int> v(n,0);
    vector<long long> dp(n+1,LLONG_MAX);
    dp[0] = -LLONG_MAX;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    // let dp[l] denote the minimum element that a sequence of length l ends in 
    // Suppose we want to extend a previous sequence with a[i]
    // We can set dp[l] = a[i] if dp[l-1] < a[i] for all l
    // at any point during the iteration:
    // we observe that the dp array is sorted
    // 1. dp[l] must be a minimum 
    // 2. dp[l] = a[i] if dp[l-1] < a[i] for all l 
    // 3. dp is sorted
    // 4. Suppose l is max such that 2 holds
    // 5. Then all l' < l-1 such that 2 holds because dp[l'] < dp[l-1] < a[i]
    //  eg dp[l] = 3 4 6, and a[i] = 5
    //  then we 2 holds for l = 2 and l = 3
    // 6. however we require dp[l] to a be minimum by (1)
    // 7. so all dp[l'] < a[i] (hence a[i] cant be a minimum), hence we don't set any dp[l'] = a[i]
    // 8. now we only know either dp[l] = a[i] or dp[l] > a[i]
    // 9. we know that it cant be dp[l] < a[i] by ass 4.
    // 10. so dp[l] >= a[i], in which case we set dp[l] = a[i]
    int ans = 1;
    for (int i = 0; i < n; i++){
        // l is the first element such that dp[l] > v[i]
        int l = upper_bound(begin(dp),end(dp), v[i]) - begin(dp);
        if (dp[l-1] < v[i] && v[i] < dp[l]){
            dp[l] = v[i];
            ans = max(ans, l);
        }
    }
    cout << ans;

}