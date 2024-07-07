#include "bits/stdc++.h"
#include <iostream>
using namespace std;


// Problem:
// Find minimum time require to produce t products
// To produce t products, we need to be given a total time, and then we have to 
// Look thru k machines and sum up the amount of products produced by each machine
// Worst case: 1 machine, produce 1e9 products, machine produces at 1 for every 1e9 secs
// Binary search on time: search space [0, 1e18], 

// Alternatively, 
// Binary search on machines sorted by time:
// Given k machines, how much time is needed to produce t products?

int main(){
    int n,t;
    cin >> n >> t;


    vector<long long> v(n,0);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    // t represents the total time 

    auto f = [n, v, t](long long dt) -> bool{
        long long sum = 0;
        for (int i = 0; i < n; i++){
            if (v[i] > dt) break;
            sum += dt / v[i];
            if (sum >= t) return true;
        }    
        return sum >= t;
    };

    // Represented as time
    long long l = 0; 
    long long h = 1e18 + 1;
    while (l < h){
        long long mid = l + (h - l) / 2;
        // INV
        // 1. Answer space / search range is [l, h)
        // 2. All elements [h, end] are valid answers

        // if mid works, then all numbers after mid works
        if (f(mid)){
            h = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l;
}