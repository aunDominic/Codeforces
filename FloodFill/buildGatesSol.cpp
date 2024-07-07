#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
void ff(int i, int j);

bool fence[4003][4003] = {false};
bool visited[4003][4003] = {false};
int maxx = 2001, minx = 2001, maxy = 2001, miny = 2001;
int main() {
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);
	int n;
	string path;
	cin >> n >> path;
	int x = 2001, y = 2001;
	map<char, pair<int, int>> dir{
	    {'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}};
	// mark fences, scaling so they are 2 units instead of 1
	for (int i = 0; i < n; i++) {
		fence[x + dir[path[i]].first][y + dir[path[i]].second] = true;
		fence[x + 2 * dir[path[i]].first][y + 2 * dir[path[i]].second] = true;
		x += 2 * dir[path[i]].first;
		y += 2 * dir[path[i]].second;
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
	}
	// expand the farm to include area outside the fences
	minx--;
	maxx++;
	miny--;
	maxy++;
	int regions = 0;
	// floodfill the farm to find the number of regions the farm is broken into
	for (int i = minx; i <= maxx; i++) {
		for (int j = miny; j <= maxy; j++) {
			if (!visited[i][j] && !fence[i][j]) {
				ff(i, j);
				regions++;
			}
		}
	}
	// answer is regions - 1 because each gate decreases the number of regions
	// by 1
	cout << regions - 1 << endl;
	return 0;
}

void ff(int i, int j) {
	if (i < minx || i > maxx || j < miny || j > maxy || visited[i][j] ||
	    fence[i][j]) {
		return;
	}
	visited[i][j] = true;
	int x[] = {-1, 0, 0, 1}, y[] = {0, -1, 1, 0};
	for (int k = 0; k < 4; k++) { ff(i + x[k], j + y[k]); }
}