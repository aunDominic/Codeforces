#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<int> v (n,0);
        
        for (int i = n - k; i <= n ; i++){
            v[i - (n-k)] = i;
        }
        int c = n - k - 1;
        for (int i = k + 1; i < n; i++){
            v[i] = c;
            c--;
        }
        for (int i = 0; i<n; i++) cout << v[i] << " ";
        cout << "\n";
    }
}