#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2 * 1e5;

int main(){
    int t; 
    cin >> t;
    while (t--){
        int n, k, x;
        cin >> n >> k >> x;
       

        vector<int> v (n+1, 0);
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        sort(v.begin()+ 1 , v.end(), greater<int>());  

        vector<int> (n+1, 0); 
        for (int i = 1; i <= n; i++){
            v[i] = v[i-1] + v[i];
        }
        int ans = -10e9;
        for (int i = 0; i <= k; i++){
            ans = max(ans, v[n] - 2 * v[min(i + x, n)] + v[i]);
        }
        cout << ans << "\n";

    }
}