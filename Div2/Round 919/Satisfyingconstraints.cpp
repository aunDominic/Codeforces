#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int t; 
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        long long lb = 0;
        long long ub = 10e9 + 7;
        vector <int> rejects;
        for (int i = 0; i < n; i++){
            long long a, k; 
            cin >> a >> k;
            if (a == 2) {
                ub = min (ub, k);
            }
            else if (a == 1){
                lb = max (lb, k);
            }
            else {
                rejects.push_back(k);
            }
        }

        int cnt = 0;
        for (int i = 0; i < rejects.size(); i++){
            if (rejects[i] >= lb && rejects[i] <= ub) {
                cnt ++;
            }
        }

        if (ub >= lb) cout << ub - lb + 1 - cnt;
        else cout << 0;
        cout << "\n";
    }
}