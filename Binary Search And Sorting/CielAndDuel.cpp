#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main () {
    int n;
    int m;
    cin >> n >> m;
    vector<int> atk; 
    vector<int> def;

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        int a; cin >> a;
        if (s == "ATK") atk.push_back(a);
        else def.push_back(a);
    }
    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());

    vector<int> ciel(m);
    for(int i = 0; i < m ; i++) cin >> ciel[i];
    sort(ciel.begin(), ciel.end());

    int i = m-1;
    int j = 0;
    int ans = 0;
    bool flag = false;
    for (; i >= 0 && j < atk.size(); i--){
        if (ciel[i] < atk[j]) {
            flag = true;
            break;
        }
        ans += (ciel[i] - atk[j]);

        j++;
    }
    if (flag) cout << ans;
    else {
        int ii = 0;
        for (int k = 0; k < def.size() && ii <= i; ii++){
            if (ciel[ii] > def[k]) k++;
        }
        for (; ii <= i; ii++){
            ans += ciel[ii];
        }
        cout << ans;
    }
    
}