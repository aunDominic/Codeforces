#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;
int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n; int m;
    cin >> n >> m;
    vector<pair<ll,ll>> v;
    for (int i = 0; i < m; i++){
        ll a; ll b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    auto f = [v, n, m](ll x) -> bool{
        int cnt = 0;
        ll prev = -x;
        for (int i = 0; i < m; i++){
            ll start = max(prev + x, v[i].first);
            ll end   = v[i].second;
            if (start > end) continue;
            int k = (end - start) / x + 1;
            cnt += k;
            prev = start + (k-1) * x;
            if (cnt >= n) return true;
        }
        return false;
    };

    ll lo = -1;
    ll hi = 1e18;
    while (lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if (f(mid)){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << hi;
}