#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

int main(){

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector <pair<int,int>> a;
        vector <pair<int,int>> b;
        vector <pair<int,int>> c;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back({x,i});
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.push_back({x,i});
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            c.push_back({x,i});
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        
        int ans = 0;


        for (int i = n-3; i < n; i++){
            for (int j = n-3; j< n; j++){
                set<int> days;
                int res = a[i].first;
                days.insert(a[i].second);
                if (days.find(b[j].second) == days.end()){
                    res += b[j].first;
                    days.insert(b[j].second);
                };
                for (int k = n-3; k < n; k++){
                    if (days.find(c[k].second) == days.end()){
                        res += c[k].first;
                        days.insert(c[k].second);
                        ans = max(ans,res);
                        days.erase(c[k].second);
                        res -= c[k].first;
                    }
                    
                }
            }
        }
        cout << ans << "\n";


    }
}
