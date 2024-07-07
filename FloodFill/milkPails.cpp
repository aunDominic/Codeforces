#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 101;
bool visited[N][N][N] = {false};
int ans = 1000000;
int X,Y,k,m;

void ff (int x, int y, int step){
    ans = min (ans, abs (m - x - y));
    if (step == k || visited[x][y][step]) return;
    visited[x][y][step] = true;
    step++;
    ff(X, y, step); // fill x to the max
    ff(x, Y, step); // fill y to the max
    ff(0, y, step); // empty x
    ff(x, 0, step); // empty y

    // Transfer x to y
    if (x + y < Y) ff (0, x + y, step);
    else ff (x + y - Y, Y, step); 
    
    // Transfer y to x
    if (x + y < X) ff (x + y, 0, step);
    else ff (X ,x + y - X, step);

    // ff(max(0, x + y - Y), min(x+y, Y), step); // either use all of x or use x as much as possible
    // ff(min(X, x + y), max(0, x + y - X), step); // either use all of y or use y as much as possible

}


int main (){
    freopen("pails.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("pails.out", "w", stdout);
    cin >> X >> Y >> k >> m;


    
    ff (0,0,0);
    cout << ans;


}