#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 100;
int n, k;
int grid[10][N] = {0};


void ff (int y, int x, int t, set <pair<int,int>> &c, vector<vector<bool>> &visited){
    if (x < 0 || x >= n || y < 0 || y >= 10 || visited[y][x] || grid[y][x] != t) return;
    visited[y][x] = true;
    c.insert({y,x});
    ff (y+1, x, t, c, visited);
    ff (y-1, x, t, c, visited);
    ff (y, x+1, t, c, visited);
    ff (y, x-1, t, c, visited);
}

int main () {
    freopen("mooyomooyo.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            char a;
            cin >> a;
            grid[j][i] = int(a) - int ('0'); // store in the form of (col, row)
        }
    }
    bool hasConnected;
    do {
        hasConnected = false;
        vector<vector<bool>> visited (10, vector<bool>(n, false));
        vector<set<pair<int,int>>> cs;

        // search for connected regions
        for (int j = 0; j < 10; j++){
            for (int i = 0; i < n; i++){
                set<pair<int,int>> c = { }; // connected regions 
                if (!visited[j][i] && grid[j][i] != 0){
                    ff (j, i, grid[j][i], c, visited);
                    cs.push_back(c);
                }
            }
        }
        // destroy connected regions 
        for (int i = 0; i < cs.size(); i++){
            if (cs[i].size() >= k){
                hasConnected = true;
                for (auto [y,x] : cs[i]){
                    grid[y][x] = 0;
                }
            }
        }

        // let the haybales fall 
        // can u simulate falling in N^2?
        for (int j = 0; j < 10; j++){
            queue<pair<int,int>> zeros;
            for (int i = n-1; i >= 0; i--){
                if (grid[j][i] == 0){
                    zeros.push({j,i});
                }
                else {
                    if (!zeros.empty()){
                        auto [y, x] = zeros.front();
                        zeros.pop();
                        grid[y][x] = grid[j][i];
                        grid[j][i] = 0;
                        zeros.push({j, i});
                    }
                }
            }
        }
    } while (hasConnected);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cout << grid[j][i];
        }
        cout << "\n";
    }
}