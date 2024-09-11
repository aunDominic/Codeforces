#include "bits/stdc++.h"
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> freq(m+1, 0);
        int cnt = 0;
        int l = 0; 
        int r = 0;
        int ans = 1e6;
        while (l <= r){
            while(cnt != m && r < n){
                int num = v[r];
                for (int i = 1; i <= sqrt(num); i++){
                    if (num % i == 0) {
                        if (i <= m) {
                            if (freq[i] == 0) cnt++;
                            freq[i]++;
                        }
                        if (num / i <= m) {
                            if (freq[num/i] == 0) cnt ++;
                            freq[num/i]++;
                        }

                    }
                }
                r++;
            }
            if (cnt == m){
                ans = min(ans, v[r-1] - v[l]);
            }
            int num2 = v[l];
            for (int i = 1; i <= sqrt(num2); i++){
                if (num2 % i == 0){
                    if (i <= m) {
                        freq[i]--;
                        if (freq[i] == 0) cnt--;
                    }
                    if (num2 / i <= m){
                        freq[num2/i]--;
                        if (freq[num2/i] == 0) cnt--;
                    }
                }
            }
            l++;
            if (cnt == m){
                ans = min(ans, v[r-1] - v[l]);
            }
        }
        if (ans != 1e6){
            cout << ans << "\n";
        } else {
            cout << -1 << "\n";
        }
        
    }
}