#include <bits/stdc++.h>
using namespace std;

struct Days{
    pair<int,int> f,s,t; // first second third largest 
    int day;
    bool operator< (const Days &other) const {return f > other.f || (f == other.f && s < other.s) || (f == other.f && s == other.s && t < other.t);}
};


int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> a (n,0);
        vector <int> b (n,0);
        vector <int> c (n,0);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];


        vector<Days> res;
        for (int i = 0; i < n; i++){
            vector<pair<int,int>> v = {{a[i],0}, {b[i], 1}, {c[i], 2}};
            sort(v.begin(), v.end(), greater<pair<int,int>>());
            Days d = Days {v[0], v[1], v[2], i};
            res.push_back(d);
        }
        int ans = 0;
        int k = 3;
        while (k--){
            sort(res.begin(), res.end());
            auto [val, act] = res[0].f;

            cout << val << " " << act << "\n";
            int d = res[0].day;
            ans += val;
            for (int i = 0; i < n; i++){
                auto [f,s,t,day] = res[i];
                if (day == d) {
                    res[i].f = {0,0};
                    res[i].s = {0,0};
                    res[i].t = {0,0};
                }
                if (f.second == act) res[i].f = {0,f.second};
                if (s.second == act) res[i].s = {0,s.second};
                if (t.second == act) res[i].t = {0,t.second};
                vector<pair<int,int>> v = {res[i].f, res[i].s, res[i].t};
                sort(v.begin(), v.end(), greater<pair<int,int>>());
                Days d = Days {v[0], v[1], v[2], i};
                res[i] = d;
            }
        }

        cout << ans << "\n";
        



        
    }
}
