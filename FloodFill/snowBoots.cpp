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
    int ans = 0;
    vector<pair<int,int>> boots;
    for (int i = 0; i < b; i++){
        int s,d;
        cin >> s >> d;
        boots.push_back({s,d});
    }
    int pos = 0;
    for (int i = 0 ; i < b; i++){
        pair<int,int> p = boots[i];
        int s = p.first;
        int d = p.second;
        bool change;
        do {
            change = false;
            int newPos = -1;

            for (int j = pos+1; j <= pos+d; j++){
                if (j < n && path[j] <= s){
                    newPos = j;
                    change = true;
                }
            }
            if (change) pos = newPos;

        } while (change);
        if (pos == n-1) {
            ans = i;
            break;
        }
    }
    cout << ans;

}