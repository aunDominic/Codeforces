#include <bits/stdc++.h>
using namespace std;

// can optimise the memory

int main() {
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;

        vector<int> a (n,0);
        vector<int> b (n,0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        vector<int> psa(n,0);
        vector<int> psb(n,0);
        psa[0] = a[0];
        psb[0] = b[0];
        for (int i = 1; i < n; i++) psa[i] = a[i] + psa[i-1];
        for (int i = 1; i < n; i++) psb[i] = max(b[i], psb[i-1]);
        
        int res = 0;
        for (int i = 0; i < min(n,k); i++){
            res = max(res, psa[i] + psb[i] * (k-i-1));
        }
        cout << res << "\n";
  

    }
}