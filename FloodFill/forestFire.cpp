#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 10;
char forest[N][N] = {};

bool change = false;
void tree(int x, int y, bool &wet){
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    if (forest[x][y] == 'W') wet = true;
}

void burn(int x, int y, vector<vector<bool>> &wetTree){
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    if (forest[x][y] == 'T' && !wetTree[x][y]) 
    {
        forest[x][y] = 'F';
        change = true;
    }
}

void evaporate(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    if (forest[x][y] == 'W')
    {
        forest[x][y] = '.';
        change = true;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    for (int i = 0 ; i < N; i++){
        for (int j = 0; j < N; j++){
            char c;
            cin >> c;
            forest[i][j] = c;
        }
    }

    int ans = 0;
    do {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        vector<vector<bool>> wetTree (N, vector<bool>(N, false));
        //protect the trees first
        change = false;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (!visited[i][j] && forest[i][j] == 'T'){
                    visited[i][j] = true;
                    bool wet = false;
                    tree(i + 1, j, wet);
                    tree(i - 1, j, wet);
                    tree(i, j + 1, wet);
                    tree(i, j - 1, wet);
                    wetTree[i][j] = wet;
                }
            }
        }

        // burn the forest
        for (int i = 0; i < N; i++){
            for (int j =0; j < N; j++){
                if (!visited[i][j] && forest[i][j] == 'F'){
                    burn(i + 1, j, wetTree);
                    burn(i - 1, j, wetTree);
                    burn(i, j + 1, wetTree);
                    burn(i, j - 1, wetTree);

                    evaporate(i + 1, j);
                    evaporate(i - 1, j);
                    evaporate(i, j + 1);
                    evaporate(i, j - 1);
                    evaporate(i + 1, j + 1);
                    evaporate(i - 1, j - 1);
                    evaporate(i + 1, j - 1);
                    evaporate(i - 1, j + 1);

                }
            }
        }
        if (change) ans++;
    }while (change);

    bool isTree = false;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (forest[i][j] == 'T') isTree = true;
        }
    }
    if (!isTree) cout << ans;
    else cout << -1;
}
