
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// forms the infected region

class cluster
{
    public:
        set<pair<int,int>> c; // set of cells that are contaminated
        set<pair<int,int>> uc; // set of cells that are next to this cluster and are uncontaminated
        int wcnt = 0;       // walls required to contain this structure 
    
};
// i literally do have 3 different floodfills 
// i could use sets instead to avoid duplicates 
// instead of keeping a visited list

void ff (int x, int y, vector<vector<int>>& isInfected, vector<vector<bool>> &visited, vector<pair<int,int>> &region){
    if (x < 0 || x >= isInfected.size() || y < 0 || y >= isInfected[0].size()) return;

    if (isInfected[x][y] == 1 && !visited[x][y]){
        visited[x][y] = true;
        region.push_back({x,y});
        ff(x+1, y, isInfected, visited, region);
        ff(x-1, y, isInfected, visited, region);
        ff(x, y+1, isInfected, visited, region);
        ff(x, y-1, isInfected, visited, region);
    }
}
int count (int x, int y, vector<vector<int>> &isInfected){
    if (x < 0 || x >= isInfected.size() || y < 0 || y >= isInfected[0].size()) return 0;
    if (isInfected[x][y] == 0) 
    {
        return 1;
    }
    return 0;                
}
int cells (int x, int y, vector<vector<int>> &isInfected, vector<vector<bool>> &visited){
    if (x < 0 || x >= isInfected.size() || y < 0 || y >= isInfected[0].size()) return 0;
    if (isInfected[x][y] == 0 && !visited[x][y]){
        visited[x][y] = true;
        return 1;
    }
    return 0;

}
void infect (int x, int y, vector<vector<int>> &isInfected){
    if (x < 0 || x >= isInfected.size() || y < 0 || y >= isInfected[0].size()) return;
    if (isInfected[x][y] == 0) isInfected[x][y] = 1;
}
bool cmp (const pair<int, vector<pair<int,int>>> &x, const pair<int, vector<pair<int,int>>> &y){return x.first < y.first;};

int containVirus(vector<vector<int>>& isInfected) {
    int m = isInfected.size();
    int n = isInfected[0].size();
    int ans = 0;

    int N = 0;
    do {
       
        vector<vector<bool>> visited (m, vector<bool> (n, false)); //infected
        vector<pair<int, vector<pair<int,int>>>> pq; // {number of cells able to infect ,infected regions}
        for (int i = 0; i < m; i++){
            for (int j = 0; j < isInfected[i].size(); j++){
                vector<pair<int,int>> region = {};
                if (!visited[i][j] && isInfected[i][j]){
                    ff(i ,j , isInfected, visited, region);
                    
                    int s = 0;
                    vector<vector<bool>> visited2 (m, vector<bool> (n, false)); //infected

                    for (int i = 0; i < region.size(); i++) {
                        auto[x,y] = region[i];
                        s += cells(x-1,y, isInfected, visited2) + cells(x+1, y, isInfected, visited2) + cells(x, y+1, isInfected, visited2) + cells(x, y-1, isInfected, visited2);
                    }
                    if (!region.empty()) pq.push_back({s, region});
                }
            }
        }
        if (!pq.empty()){
            sort(begin(pq), end(pq), cmp);
            auto [c, region] = pq.back();
            int s = 0;

            for (int i = 0; i < region.size(); i++) {
                        auto[x,y] = region[i];
                        s += count(x-1,y, isInfected) + count(x+1, y, isInfected) + count (x, y+1, isInfected) + count(x, y-1, isInfected);
                    }
            ans += s;
            for (int i = 0; i < region.size(); i++){
                auto [x, y] = region[i];
                isInfected[x][y] = 3; // blocked off from the rest of the world
            }
            for (int i = 0; i < pq.size() - 1; i++){
                auto [cnt, reg] = pq[i];
                for (int j = 0; j < reg.size(); j++){
                    auto [x, y] = reg[j];
                    infect(x+1, y, isInfected);
                    infect(x-1, y, isInfected);
                    infect(x, y+1, isInfected);
                    infect(x, y-1, isInfected);
                }
            }
        }
        N = pq.size();
    } 
    while (N > 1);

    return ans;
}


int main (){
    vector<vector<int>> isInfected = {{0,1,0,1,1,1,1,1,1,0},{0,0,0,1,0,0,0,0,0,0},{0,0,1,1,1,0,0,0,1,0},{0,0,0,1,1,0,0,1,1,0},{0,1,0,0,1,0,1,1,0,1},{0,0,0,1,0,1,0,1,1,1},{0,1,0,0,1,0,0,1,1,0},{0,1,0,1,0,0,0,1,1,0},{0,1,1,0,0,1,1,0,0,1},{1,0,1,1,0,1,0,1,0,1}};
    cout << containVirus(isInfected);
}