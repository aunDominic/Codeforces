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

int main(){
    int t;

    cin >> t;
    while (t--){
        int n;
        int m;
        int k;
        cin >> n >> m >> k;
        vector<int> v(n,0);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        multiset<int> b;
        for (int i = 0; i < m; i++){
            int a;
            cin >> a;
            b.insert(a);
        }
        int l = 0;
        int r = m-1;
        int c = 0;
        
        int ans = 0;
        map<int,int> B;
        for (int i = 0; i < m; i++){
            B[v[i]]++;
        }
        for (auto [key,val]: B){
            c += min((int) b.count(key), val);
        }
        while (l <= n - m){
            if (c >= k) ans++;
            B[v[l]]--;
            l++;
            r++;
            if (r >= n) break;
            B[v[r]]++;
            if (v[l-1] != v[r]){
                if (B[v[l-1]] < b.count(v[l-1])) c--;
                if (B[v[r]] <= b.count(v[r])) c++;
            }

        }
        cout << ans << "\n";
    }
}