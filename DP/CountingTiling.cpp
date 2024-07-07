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
int n = 3;
int m = 2;
const int M = 1e9 + 7;

struct P{
    int x, y;

    P (int x, int y){
        this-> x = x;
        this-> y = y;
    }
    P operator+ (const P& other){
        return P(this->x + other.x, this->y + other.y);
    
    }
    bool operator== (const P& other){
        return this->x == other.x && this->y == other.y;
    }
    bool operator< (const P &other){
        if (this-> x == other.x) return this->y < other.y;
        return this->x < other.x;
    }
};

vector<vector<bool>> visited(n, vector<bool>(m, false));


bool outbounds(int x, int y){
    return x >= n || y >= m || x < 0 || y < 0 || visited[x][y];
}


int tiling(P f, P s, int count){
    if (outbounds(f.x, f.y) || outbounds(s.x, s.y)) return 0;
    count += 2;
    if (count == n * m) return 1;
    visited[f.x][f.y] = true;
    visited[s.x][s.y] = true;
    
    //
    //  for a particular point in a grid,  i can spawn in 4 directions
    //      |
    //    <- ->
    //      |
    //      ..
    //     .xx.
    //      ..
    // there are six spots i can spawn it in 


    ///
    //      ...
    //      ...   
    //      ...
    //      ...
    //
    ///
    
    vector<P> dirs = {P(1,0), P(0,1), P(-1,0), P(0,-1)};
    long long ans = 0;
    for (auto d: dirs){
        P spot_f = f + d;
        P spot_s = s + d;
        for (auto v: dirs){
            P spot_ff = spot_f + v;
            P spot_ss = spot_s + v;

            if (spot_ss < spot_s) swap(spot_s, spot_ss);
            if (spot_ff < spot_f) swap(spot_f, spot_ff);
            if (!(spot_f == spot_ff)) {
                ans += tiling(spot_f, spot_ff, count) % M;
            }
                
            if (!(spot_s == spot_ss) && !(spot_f == spot_s) && !(spot_ff == spot_ss)) {
                ans += tiling(spot_s, spot_ss, count) % M;
            }
            
        }
    }
    visited[f.x][f.y] = false;
    visited[s.x][s.y] = false;
    return ans;
}

int main (){
    // cin >> n >> m;
    // vector<vector<bool>> visited(n, vector<bool>(m, false));

    cout << tiling(P(0,0), P(0,1), 0);
    cout << tiling(P(0,0), P(1,0), 0);
}