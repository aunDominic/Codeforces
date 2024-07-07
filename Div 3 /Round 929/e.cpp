#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
#include <numeric>
#include <string.h>
#include <random>
#include <cassert>
#include <iomanip>
#include <ios>
#include <map>
#include <climits>
using namespace std;

int calcSum (int u, int n){
    return ((2 * u - n + 1) * n) / 2;
}
int main (){
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        vector<int> v(n+1,0);
        for (int i = 0; i < n; i++){
            cin >> v[i+1];
        }
        for (int i = 1; i <= n; i++){
            v[i] += v[i-1];
        }

        int q;
        cin >> q;

        while (q--){
            int l, u;

            cin >> l >> u;
            int firstl = l;
            // r can go up to u - 1;
            int count = 0;
            bool flag = true;
            int ls = v[l-1];
            int r = n;
            l--;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                int x = v[mid] - ls;
                if (x <= u){
                    l = mid;
                } else {
                    r = mid - 1;    
                }
            }
            // Max value is when l = u or l = u + 1
            // l+1 is the first value that is greater than u
            // l is the max value at most u 
            // So we check both l and l+1
            double fst = (double) u + 0.5 - v[l+1] + ls;
            double snd = (double) u + 0.5 - v[l] + ls;
            if (l+1 <= n && (abs(fst) < abs(snd))) cout << l+1;
            else cout << max(firstl,l); 
            cout << " ";
        }
        cout << "\n";
    }
}