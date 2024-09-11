#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e3;
const int M = 1e3;
bool visited[N][M];
int n, m;
vector<vector<char>> grid(N, vector<char>(M, 'x'));
void ff(int x, int y){
    if (visited[x][y] || x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#') return;
    visited[x][y] = true;
    ff(x + 1, y);
    ff(x - 1, y);
    ff(x, y + 1);
    ff(x, y - 1);
}
int main(){
     cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j] && grid[i][j] == '.'){
                ff(i, j);
                ans++;
            }
        }
    }
    cout << ans;

}