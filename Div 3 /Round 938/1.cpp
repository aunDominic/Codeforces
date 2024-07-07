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

int main () {
    int t;
    cin >> t;
    while (t--){
        int n,a,b;
        cin >> n >> a >> b;
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++){
            if ((n-i) % 2 == 0){
                ans = min(ans, i * a + (n-i)/2 * b);
            }
        }
        cout << ans << "\n";
    }
}