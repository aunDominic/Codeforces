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


    long long ans = 1e9 + 1;
  
    long long l = 0;
    long long r = n-1;
    while (l < r && k > 0){
        if (l + 1 > n - r){
            // More elements on left side, so we should decrement the right side
            if (r > 0){
                long long diff = v[r] - v[r-1];
                v[r] -= min(diff, k / (n - r));
                k -= min(k , diff * (n - r));
            }
            ans = min(ans, v[r] - v[l]);
            r--;
        } else {
            // More elements on the right side, so we should increment the left side.
           
            if (l + 1 < n){
                long long diff = v[l+1] - v[l];
                v[l] += min(diff, k /(l+1));
                k -= min(k, diff * (l+1));
            }
            ans = min(ans, v[r] - v[l]);
            l++;
        }
    }

    if (ans == 1e9 + 1) cout << -1;
    else cout << ans;
    

}