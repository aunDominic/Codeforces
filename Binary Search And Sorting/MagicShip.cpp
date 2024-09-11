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
int main(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n;
    vector<char> v(n,0);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<pair<ll, ll>> pf(n+1,{0,0});

    for (int i = 0; i < n; i++){
        pair<ll,ll> tmp;
        switch (v[i]){
            case 'U':
                tmp = {0,1};
                break;
            case 'D':
                tmp = {0, -1};
                break;
            case 'L':
                tmp = {-1, 0};
                break;
            case 'R':
                tmp = {1, 0};
                break;
        }
        pf[i+1] = pf[i] + tmp;
    }   
    auto f = [pf, n, x1, y1, x2, y2](ll days)-> bool{
        pair<ll,ll> ship = {x1, y1};

        ship = ship + pf[n] * (days/n) + pf[days % n];
        ll cnt = abs(ship.first - x2) + abs(ship.second - y2);
        if (cnt <= days) return true;
        else return false;

    };

    ll lo = 0;
    ll hi = 1e14 + 1;

    while (lo < hi){
        ll mid = lo + (hi - lo)/2;
        if (f(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }

    }
    if (hi == 1e14 + 1) cout << -1;
    else cout << lo;

}
