// #define NDBEUG
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

int main (){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<int>v(n,0);
        for (int i =0 ; i < n ;i++){
            cin >> v[i];
        }
        int l = 0;
        int r = n-1;
        int ans = 0;
        
        bool first = true;
        // u r dumb
        // left side has k+1/2 moves
        // rightside has k/2 moves
        long long lA = (k+1)/2;
        long long rA = k/2;
        while (l <= r){
            if (lA >= v[l]) {
                ans++;
                lA-= v[l];
                l++;
            } else {
                v[l] -= lA;
                break;
            }
        }
        while (r >= l){
            if (rA >= v[r]){
                ans++;
                rA-= v[r];
                r--;
            } else break;
        }
        cout << ans << "\n";
    }

}
