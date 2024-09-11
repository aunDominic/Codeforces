#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] *= 2;
    }
    sort(v.begin(), v.end());

    auto findLocation = [v, n] (long long x, long long rad) -> bool {
        // Given an initial radius of explosion, find the minimum starting location
        // That is able to explode all haybales to the right,
        // After returning, then we check if this minimum location can explode all haybales to the left
        // If that is not possible, then this radius doesnt work 
        
        int cnt = 0;
        long long last = x;
        int i = 0;
        // i want to find the max on the right such that v[j] <= last + rad - cnt;
        while (i < n){ 
            int j = i;
            while(j < n){
                if (j + 1 < n && v[j+1] > last + rad - cnt){
                    break;
                }
                j++;
            }
            if (j == i) return false; 
            if (j == n) return true;
            last = v[j];
            cnt += 2;
            i = j;
        }
        return true;
    }; 
    long long min = 0;
    long long max = 3e9;    
    auto findExplosion = [v, n, findLocation] (long long rad) -> bool {

        // Given a radius, 
        long long l = v[0]; 
        long long r = v[n-1];
        while (l < r){
            long long mid = l + (r - l) / 2;
            if (findLocation(mid, rad)){
                r = mid;
            } else{
                l = mid + 1;
            }
        }
        int i = 0; 
        for (; i < n; i++){
            if (l - rad <= v[i]) break;
        }
        int cnt = 0;
        int last = v[i];
        while (i >= 0){
            int j = i;
            while (j >= 0){
                if (j - 1 >= 0 && v[j-1] < last - rad + cnt){
                    break;
                }
                j--;
            }
            if (j == i) return false;
            if (j == -1) return true;
            last = v[j];
            cnt += 2;
            i = j;
        }
        return true;
    };
    while (min < max){
        long long mid = min + (max - min) / 2;
        if (findExplosion(mid)){
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    cout << min / 2 << '.' << (min % 2 ? 5 : 0) << '\n';    

}