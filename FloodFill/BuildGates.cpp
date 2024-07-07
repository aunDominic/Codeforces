#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int N = 4003;

bool gates[4003][4003] = {false};
bool visited[4003][4003] = {false};
int maxx = 2001, minx = 2001, maxy = 2001, miny = 2001;

void ff (int x, int y){

    if (x < minx || x > maxx || y < miny || y > maxy || visited[x][y] || gates[x][y]) return;
    visited[x][y] = true;
    ff (x+1, y);
    ff (x-1, y);
    ff (x, y+1);
    ff (x, y-1);

}
void pretty(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (gates[i][j]) cout << "X ";
            else if (visited[i][j]) cout << "O ";
            else cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int main (){
    freopen("gates.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("gates.out", "w", stdout);
    int n; 
    cin >> n;

    int sx, sy;
    sx = 2001; sy = 2001;
    gates[sx][sy] = true;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        if (c == 'N'){
            sy++;
            gates[sx][sy] = true;
            sy++;
        }
        else if (c == 'S'){
            sy--;
            gates[sx][sy] = true;
            sy--;
        }
        else if (c == 'W'){
            sx--;
            gates[sx][sy] = true;
            sx--;
        }
        else if (c == 'E'){
            sx++;
            gates[sx][sy] = true;
            sx++;
        }
        gates[sx][sy] = true;
        minx = min(minx, sx);
		maxx = max(maxx, sx);
		miny = min(miny, sy);
		maxy = max(maxy, sy);
    }
    int ans = 0;
	minx--;
	maxx++;
	miny--;
	maxy++;
    for (int i = minx; i <=maxx; i++){
        for (int j = miny; j <= maxy; j++){
            if (!visited[i][j] && !gates[i][j]){
                ff (i, j);
                ans++;
            }
        }
    }
    if (ans > 0) ans--;
    cout << ans;


}