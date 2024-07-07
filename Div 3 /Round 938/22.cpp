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
    while (t--){
        int n,c,d;
        cin >> n >> c >> d;
        map<int, int> a;
        int start = INT_MAX;
        for (int i = 0; i < n*n; i++){
            int x;
            cin >> x;
            a[x]++;
            start = min(start, x);
        }
        vector<vector<int>> v(n, vector<int>(n,0));
        v[0][0] = start;
        bool ans = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0) continue;
                if (j > 0) v[i][j] = v[i][j-1] + d;
                if (i > 0) {
                    ans = v[i][j] == v[i-1][j] + c;
                    v[i][j] = v[i-1][j] + c;
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[v[i][j]] == 0){
                    ans = false;
                    break;
                }
                a[v[i][j]]--;

            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}