#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;

pair<ll,ll> operator+(const pair<ll,ll> &f, const pair<ll,ll> &s){
    return {f.first + s.first, f.second + s.second};
}
pair<ll,ll> operator*(const pair<ll,ll> &f, const ll &s){
    return {f.first * s, f.second * s};
}

int main (){
    int t;
    cin >> t;
    while (t--){
        ll tc, tm, n;
        cin >> n >> tc >> tm;
        
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        for (int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i];
            // a > b
        }

        auto f = [a,b,c,n,tc,tm] (ll m) -> bool {
            ll lx = max(1LL, tc - m);
            ll ux = min(tc, tc - (m - tm + 1));
            for (int i = 0; i < n ;i++){
                ll d = tm + tc - m;
                if (a[i] - b[i] > 0){
                    ux = min(ux, (c[i] - b[i] * d ) / (a[i]-b[i]));
                } else if (a[i] - b[i] < 0){
                    lx = max(lx, (- c[i] + b[i] * d + b[i] - a[i] - 1) / (b[i] - a[i]));
                } else {
                    if (a[i] * d > c[i]) return false;
                }

            }
            return (lx <= ux); 
        };
        ll lo = 0;
        ll hi = tc + tm - 2;
        while (lo < hi){
            ll mid = lo + (hi - lo) / 2;
            if (f(mid)){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
    }
}