#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    /*
    1 2 3 4 5
    2 4 6 8 10
    3 6 9 12 15
    4 8 12 16 20
    5 10 15 20 25
    */

    // n + n - 1 = n^2 /2 
    // We binary search on the answer space.

    // Answer space [1, n^2 = 1e12]
    // The answer is such that >= n^2 / 2 + 1(n is odd) of numbers is is less than or equal to it.
    // the function f is monotonically decreasing, clearly if x works, then y >= x works; 

    long long lo = 1;
    long long hi = 1e12 + 1;
    auto f = [n](long long x) -> bool{ // eg x = 8
        long long cnt = 0;
        for (int i = 1; i <= n; i++){ 
            cnt += min(x / i, n);
        }
        return cnt >= n * n / 2 + 1;
    };
    while (lo < hi){
        long long mid = lo + (hi - lo) / 2;
        // mid works, then all y after mid works
        if (f(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;

}