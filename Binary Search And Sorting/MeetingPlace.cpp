#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long double> x(n,0);
    vector<long double> v(n,0);

    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> v[i];

    long double lo = 0;
    long double hi = 1e9 + 1;
    int cnt = 0;
    auto f = [x,v, n](long double t) -> bool{
        long double l = -DBL_MAX;
        long double r = DBL_MAX;
        for (int i = 0; i < n; i++){
            // Suppose l and r is the range of where all drivers can meet.
            // now when computing the ith driver
            // we consider the range of it can travel in both directions. call it l', r'
            // this range must be within [l, r]
            // if [l, l', r', r]
            // then [l', r'] is the new range
            // if [l, l', r, r', then [l', r] is the new range
            // if [l', l, r',r] then [l, r']
            // if [l', r', l, r] then false
            // if [l, r, l', r'] then false
            long double rprime = x[i] + v[i] * t;
            long double lprime = x[i] - v[i] * t;
            if (lprime > r) return false;
            if (rprime < l) return false;

            if (lprime > l) l = lprime;
            if (rprime < r) r = rprime;
        }
        return true;
    };
    while(lo < hi && cnt <= 200){
        long double mid = lo + (hi - lo) / 2;
        if (f(mid)){
            hi = mid;
        } else {
            lo = mid;
        }
        cnt ++;
    }

    cout << setprecision(20) << lo;
}