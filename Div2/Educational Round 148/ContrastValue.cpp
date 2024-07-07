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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<long long> v(n,0);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        // 2 Observations

        // if all a1 .. ak is monotonically increasing
        // a1 <= a2 <= ... <= ak
        // then |a1 - a2| + |a2 - a3| 
        // = a2 - a1 + a3 - a2 
        // = a3 - a1
        // so we can remove a2

        // what if there is a hill
        // a1 <= a2 >= a3
        // then |a1 - a2| + |a2 - a3|
        // = a2 - a1 + a2 - a3
        // = 2a2 - a1 - a3
        // then we can't delete any elements

        // In every sequence
        // either ai < ai+1 
        // or ai = a+1
        // or ai > ai+1
        // if ai = a+1 
        // we can safely delete ai

        // then we can delete all elements except a1 and ak

        // likewise if monotonically decreasing
        long long cmp = v[0];
        auto last = unique(v.begin(), v.end());
        v.erase(last, v.end());
        n = v.size();
        int ans = n;
        for (int i = 1; i < n-1; i++){
            if (cmp < v[i] && v[i] < v[i+1] ||
                cmp > v[i] && v[i] > v[i+1]) ans--;
            else{
                cmp = v[i];
            }
        }

        cout << ans << "\n";
    }
}