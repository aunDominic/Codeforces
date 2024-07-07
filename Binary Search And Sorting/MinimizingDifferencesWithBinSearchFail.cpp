#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main(){
    long long n; cin >> n;
    long long k; cin >> k;

    // Binary search on answer space:
    // answers space = [0, 1e9]
    // We check if its possible to achieve a minimum difference of x.
    // Clearly if a minimum difference of x is possible, then y > x is also possible 
    // if we use less moves.
    // Increasing and decreasing are equivalent, -> difference is always affected 
    // first sort the array
    // then we must add 

    // 9 
    // 4 5 5 7 5 4 5 2 4 3
    // 3 4 5 7

    vector<long long> v(n,0);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    vector<long long> pf(n+1,0);
    for (int i = 0; i < n; i++){
        pf[i+1] = pf[i] + v[i];
    }

    long long lo = 0;
    long long hi = 1e9 + 1;

    auto f = [v, n, k, pf](long long x) -> bool{

        // We want to check if its possible to achieve a difference of x 
        // using less than or equal to k moves.
        // If its possible, then the maximal element - minimal element must be equal to x 
        // Then there must be l minimal elements and r maximal elements.
        // We should strive to use as few moves as possible to achieve this. 
        // We can use a prefix sum, since we can only make k moves
        // we search all possible l's, increase each element to v[l]
        // calculate the number of moves used.
        // Then the remaining will be used for r's such that the difference 
        // is exactly x. 
        // check if the number of moves is possible
        // For l's it always optimal to increase the numbers towards the maximum number
        // For r's it's always optimal to decrease towards the minimum number.
        for (int l = 0; l < n; l++){
            // Increase all elements before l to v[l]
            // This takes cnt amount of operations. 
            // There are l elements before the l-th element, we increase each element 
            // to v[l] as v[l] is bigger, 
            long long cnt = v[l] * l - pf[l];
            if (cnt > k) continue;
            // all elements from l equal to v[l] 
            // Since the array is sorted
            // diff will decrease as l increases
            // v[l] is the current minimum
            long long diff = v[n-1] - v[l];
            if (diff <= x) return true;
            long long toChange = v[l] + x;
            int r = upper_bound(v.begin(), v.end(), toChange) - v.begin();
            cnt += pf[n] - pf[r] - toChange * (n - r) ;
            if (cnt <= k) return true;   
        }
        return false;
        
    };
    while (lo < hi){
        long long mid = lo + (hi - lo) / 2;
        if (f(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (hi == 1e9 + 1) cout << -1;
    else cout << lo;

}