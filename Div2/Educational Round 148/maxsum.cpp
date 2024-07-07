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

int main() {
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<long long> v(n+1,0);
        for (int i = 1 ; i <= n ;i ++){
            cin >> v[i];
        }
        sort (v.begin(),v.end());
        int l = 0;
        int r = n-1;

        vector<long long> lsum(n+1,0);
        for (int i = 1; i <= n; i++){
            lsum[i] = lsum[i-1] + v[i];
        }
        long long ans = 0;
        for (int i = 0; i <= n; i+= 2){
            long long lrem = lsum[i];
            int j = k - i / 2; // available moves to cut from the right
            // take j terms off from the right
            long long rrem = 0;
            if (j > 0){
                rrem = lsum[n] - lsum[n-j];
            }
            ans = max(ans, lsum[n] - lrem - rrem);
        }

        cout << ans << "\n";
    }
}