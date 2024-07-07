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
int n, k;
const int N = 1e4;
vector<int> v(N+1,0);

/** A data structure that can answer point update & range minimum queries. */
template <class T> class MaxSegmentTree {
  private:
	const T DEFAULT = INT_MIN;

	vector<T> segtree;
	int len;

  public:
	MaxSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
		}
	}

	/** @return the minimum element in the range [start, end) */
	T range_max(int start, int end) {
		T max = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { max= std::max(max, segtree[start++]); }
			if (end % 2 == 1) { max = std::max(max, segtree[--end]); }
		}
		return max;
	}
};
// int teamwork(int n, int c, vector<int> &v){
//     if (n == 0) return 0;

//     // teamwork(n ,c) = the optimal sum by assigning the first n elements into a group of size c
//     // assign the first n-1 elements into group of size up to c, and the nth element into its own group
//     int ans = 0;
//     for (int i = 0; i < c; i++){
//         // maxx is maxx in range [l .. n]
//         int l = n - i;
//         if (l >= 1) ans = max(rmq[l][n] * (n - l + 1) + teamwork(l - 1, c, v), ans);

//     }
//     return ans;
// }

int main () {
    freopen("teamwork.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("teamwork.out", "w", stdout);
    cin >> n >> k;

    MaxSegmentTree<int> segtree(n);
    for (int i = 0; i < n; i++){
        cin >> v[i+1];
        segtree.set(i, v[i+1]);
    }

    // total number of groups 
    // it is always better to use large group as possible 
    // problem is to determine how to assign n/k groups across n cows
    // every element either is in its own group
    // or joins the previous group
    
    // let dp[i][j] = the maximum sum up to i 
    // when an element i is in group of size up to j
    // dp[i][j] = max for all j . max [i-j .. i] * (i - j) + dp[i-1][j]
    // sanity check: dp[n][k] the maximum sum up to i when element n is in group up to size k
    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 0;

    // dp[0][k] = 0;
    // dp[1][k] = v[i];
    // dp[n][1] = sum up to n;


    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (i - j >= 0){
                int maxx = segtree.range_max(i-j, i); // maxx between (i-j .. i]
                dp[i][j] = max(dp[i][j], maxx * j + dp[i-j][k]);
            }
            // u dont need 2d dp if your doing this 
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    cout << dp[n][k];

    // dp doesnt need to be 2d 
    // but its still O(n)


}