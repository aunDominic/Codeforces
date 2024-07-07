#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    freopen("snowboots.in", "r", stdin);
	// the fosnowbootsng line creates/overwrites the output file
	freopen("snowboots.out", "w", stdout);
    int n, b; 
    cin >> n >> b;
    vector<int> path; 
    for (int i = 0; i < n; i++){
        int a; cin >> a; path.push_back(a);
    }
    vector<pair<int,int>> boots;
    for (int i = 0; i < b; i++){
        int s,d;
        cin >> s >> d;
        boots.push_back({s,d});
    }
    const int N = 250;
    const int B = 250;

    bool visited[B][N] = {false}; 
    visited[0][0] = true;
    // visited[n][b] 
    //    = which boot boots thrown away when visited path n with boots bth
    // 
    int ans = 1e9;
    for (int j = 0; j < b; j++){
        pair<int,int> p = boots[j];
        int s = p.first;
        int d = p.second;
        // we
        for (int i = 0; i < n; i++){

            if (path[i] > s) continue;
            

            for (int b2 = 0; b2 < j; b2++){
                if (visited[b2][i]) visited[j][i] = true; 
            }
            for (int i2 = 0; i2 < i; i2++){
                if (visited[j][i2] && i2 + d >= i) visited[j][i] = true;
            }
            if (i == n-1 && visited[j][i]) ans = min (ans, j);
        }
    }
    cout << ans;
}