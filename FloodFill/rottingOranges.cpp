#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

void ff (int x, int y, vector<vector<int>>& grid, vector<pair<int,int>> &tmp){
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
    if (grid[x][y] == 1) {
        grid[x][y] = 2; 
        tmp.push_back({x,y});
    }
}
int orangesRotting(vector<vector<int>>& grid) {
    vector<pair<int,int>> rotten;
    for (int m = 0; m < grid.size(); m++){
        for (int n = 0; n < grid[m].size(); n++){
            if (grid[m][n] == 2) rotten.push_back({m,n});
        }
    }

    int ans = 0;
    while (!rotten.empty()){
        vector<pair<int,int>> tmp = {}; 
        // for (int i = 0; i < rotten.size(); i++) cout << rotten[i].first << " " << rotten[i].second;
        for (int i = 0; i < rotten.size(); i++){
            auto [x,y] = rotten[i];
            ff(x+1,y, grid, tmp);
            ff(x, y+1, grid, tmp);
            ff(x-1,y, grid, tmp);
            ff(x, y-1, grid, tmp);
        }
        if (!tmp.empty()) ans++;
        rotten = tmp;
    }
    return ans;     
}

int main() {
    cout << "lol";
    vector<vector<int>> input = {{2,1,1},{0,1,1},{1,0,1}};
    int ans = orangesRotting(input);
    cout << ans;
}