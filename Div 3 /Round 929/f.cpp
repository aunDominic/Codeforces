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

struct S{
    int x, y, t;
    S(int nx, int ny, int nt){
        x = nx;
        y = ny;
        t = nt;
    }
};


int main (){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj (n, vector<int> (m,0));
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m; j++){
                cin >> adj[i][j];
            }
        }
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        int ans = -1;
        queue<S> q;
        q.push(S(0,0,0));
        while(!q.empty()){
            S s = q.front();
            int x = s.x;
            int y = s.y;
            int dt = s.t;
            q.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            if (x == n-1 && y == m-1) {
                ans = dt;
                break;
            }
            if (adj[(x + dt + 1) % n][y] == 0 && adj[(x+dt + 2) % n][y] == 0){
                q.push(S((x+1) % n, y, dt+1));
            }
            if (y+1 < m && adj[(x+dt+1) % n][y+1] == 0) {
                q.push(S(x, y+1 , dt+1));
            }
            if (y == m-1) q.push(S((x + n -1) % n, y, dt+1));
        }
        cout << ans << "\n";
        
    }
}