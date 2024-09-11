#include "bits/stdc++.h"
#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int N = 1e3;
const int M = 1e3;
bool visited[N][M];
int n, m;
vector<vector<char>> grid(N, vector<char>(M, 'x'));

struct State{
    int x;
    int y;
    char c;
};
int main(){
    cin >> n >> m;
    pair<int,int> start;
    pair<int,int> end;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }
    vector<vector<pair<int,int>>> parents(n, vector<pair<int,int>>(m, {-2,-2}));
    vector<vector<char>> direction(n, vector<char>(m, 0));

    queue<State> q;
    q.push({start.first, start.second, '0'});

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<char> dir = {'R', 'L', 'D', 'U'};
    while(!q.empty()){
        State cur = q.front(); q.pop();
        int x = cur.x; int y = cur.y;
        visited[x][y] = true;
        if (grid[x][y] == 'B') {
            cout << "YES\n";
            string path = "";
            int nx = x;
            int ny = y;
            while (parents[nx][ny].first != -2){
                path += direction[nx][ny];
                int mx = parents[nx][ny].first;
                ny = parents[nx][ny].second;
                nx = mx;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            cout << path;
            return 0;
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#'){
                visited[nx][ny] = true;
                q.push({nx, ny, dir[i]});
                parents[nx][ny] = {x, y};
                direction[nx][ny] = dir[i];
            }
        }   
    }
    cout << "NO\n";


}