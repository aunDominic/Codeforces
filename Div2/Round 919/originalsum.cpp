#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    int t; 
    cin >> t;
    while (t--){
        int n, k, x;
        cin >> n >> k >> x;
        int r = min(k,x);
        vector<int> v; 
        
        for (int i = 0; i < n; i++){
            int a; 
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());  
 
        vector<int> v2 (n,0);
        for (int i = 0 ; i < n ; i++){
            v2[i] = -v[i];
        }
        vector<int> psum (n+1,0);
        psum[0] = 0;
        for (int i = 0; i < n; i++){
            psum[i+1] = psum [i] + v[i];
        }
        vector<int> psum2(n+1,0); 
        for (int i = n; i >= 0; i--){
            psum2[i] = psum2[i+1] + v2[i];
        }
        int ans = -10e9 ;
        for (int i = n; i >= n - k; i--){
             
            if (i - x >= 0) ans = max(ans, psum[i-x] + psum[i-x] - psum[i]);
            else ans = max (ans, -psum[i]);
        }
        cout << ans;
        cout << "\n";
 
    }
}