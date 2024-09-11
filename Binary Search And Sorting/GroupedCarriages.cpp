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
struct range{
    ll start;
    ll end;
    ll val;
};

int main(){
    ll n; cin >> n;
    vector<ll> a(n,0);
    vector<range> ranges(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        ranges[i] = {max(0LL,i - x), min(n, i + x + 1), a[i]};
    }
    sort(ranges.begin(), ranges.end(), [](const range& l, const range& r) {
        return l.start < r.start;
    });

    // We need to find a way to arrange passengers such that each carriage only holds <= x people
    auto f = [n,ranges,a](ll z) -> bool{
        vector<range> curr_ranges = ranges;
        auto comp = [&](const int &l, const int &r) -> bool {
            return !(curr_ranges[l].end < curr_ranges[r].end);
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        int j = 0;
        for (int i = 0; i < n ; i++){
            while (j < n && curr_ranges[j].start <= i){
                pq.push(j);
                j++;
            }
            int dest = 0; 
            while (!pq.empty()){
                int toDonate = pq.top();
                pq.pop();
                if (!(i < curr_ranges[toDonate].end)) continue;

                if (curr_ranges[toDonate].val + dest <= z) { 
                    dest += curr_ranges[toDonate].val;
                    curr_ranges[toDonate].val = 0;
                } else { 
                    // dest = Z effectively 
                    curr_ranges[toDonate].val -= (z - dest);
                    pq.push(toDonate);
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (curr_ranges[i].val != 0) return false; 
        }
        return true;
    };
    ll lo = 0;
    ll hi = 1e9 + 1;


    while (lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if (f(mid)){
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    
    cout << lo;

}