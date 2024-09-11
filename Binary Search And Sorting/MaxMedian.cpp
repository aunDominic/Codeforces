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

    // The max median is <= the maximal number;
    // If its the maximal number, the subarray must contain only the maximal number
    // eg [9,9,9]
    // if its [4,9] it will never work
    // So if its the maximal number, the either entire subarray is the maximal number
    // or it is length 1 (same thing) (cannot be length 2 and have any number other then the maximal number)

    // Similarly, if its the second maximal number, [7,8,9] [7,8,8] [7,7,8] [7,7,8,9,9], [7,8,8,8]
    // it must contain equal number of numbers which are less than or equal to it 
    // and equal number of numbers that are greater than or equal to it

    // Prefix sums? 

    // Count the number of terms that are bigger than a median, m


    // 1 1 4 5 7 6 8 2

    int n; cin >> n;
    int k; cin >> k;

    vector<int> v(n,0);
    for (int i = 0; i < n; i++) cin >> v[i];

    
    // Let f be the boolean function that evaluates to true
    // when m <= x 
    // where m is a given median, and x is the largest median of a subarray
    // Then, if for some guess m_i >= x, then m_j < m_i such that m_j >= x
    // So the function is monotonically decreasing.
    // So we can use binary search to find the maximal value
    auto f = [v,n,k](int m) -> bool{
        vector<int> pf(n+1, 0);
        for (int i = 0; i < n; i++){
            pf[i+1] = pf[i];
            if (v[i] >= m) pf[i+1]++;
            else pf[i+1]--;
        }
        int mn = pf[0]; 
        for (int r = k; r <= n; r++){
            if (pf[r] - mn > 0) return true;
            mn = min(mn, pf[r - k + 1]);
        }
        return false;
    };

    int lo = -1; 
    int hi = n;

    while (lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid)){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << hi;
}