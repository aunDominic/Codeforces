#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

int main (){
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    long long n, t;
    cin >> n >> t;
    multiset<long long> endTimes;
    for (int i = 0; i < n; i++){
        long long x, v;
        cin >> x >> v;
        long long endTime = x + v * t;
        auto it = endTimes.upper_bound(-endTime);
        if (it == endTimes.end()){
            endTimes.insert(-endTime);
        } else {
            endTimes.erase(it);
            endTimes.insert(-endTime);
        }
    }
    cout << endTimes.size();
}