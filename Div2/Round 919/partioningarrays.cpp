#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main (){
    int t;
    cin >> t; 
    while (t--){
        int n;
        cin >> n; 
        vector<int> v;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        int ans = 0;
        for (int k = 1; k <= n; k++){
            if (n % k == 0)
            {
                int g = 0;
                for (int i = 0; i + k < n; i++){
                    g = gcd(g, abs(v[i] - v[i+k]));
                }
                ans += (g != 1);
            }
                
        }
        cout << ans << "\n";
    }
}