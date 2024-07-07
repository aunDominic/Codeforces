#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        string s; 
        cin >> s;
        vector<int> v(27, 0);

        for (int i = 0; i < s.length(); i++){
            char c = char (tolower(int(s[i])));
            int timeSolve = int(c) - int('a') + 1; 
            v[timeSolve] += 1;
        }
        int ans = 0;
        for (int i = 1; i <= 26; i++){
            if (v[i] >= i) ans++;
        }
        cout << ans << "\n";
    }
} 