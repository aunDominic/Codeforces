// #define NDBEUG
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

struct Rect{
    int x, y;
    Rect(int x, int y){
        this-> x = x;
        this-> y = y;
    }
    bool operator< (const Rect &other) const {
        if (this-> x == other.x){
            return this-> y < other.y;
        }
        return this-> x < other.x;
    }
};
int w, h;
vector<Rect> desired;
bool isDesired (int x, int y){
    vector<Rect> :: iterator r = lower_bound(desired.begin(), desired.end(), Rect(x,y));
    if ((*r).x == x && (*r).y == y){
        return true;
    }   
    return false;
}

// let phidias(x,y) denote the min number of area wasted of when cutting a rectangle of width x and height y
// clearly phidias(x,y) = 0 when x y is already desired
// otherwise we try to cut the rectangle into desired areas 
const int N = 601;
vector<vector<int>> dp(N, vector<int>(N,INT_MAX));
int phidias(int x, int y){
    // if (x,y) desired, return 0
    int ans = 0;
    if (!isDesired(x,y)) ans = x * y;
    else return 0;
    if (dp[x][y] != -1) return dp[x][y];
    for (int i = 1; i < x; i++){
        // cut the rectangle into 
        // (i, y) & (x - i, y) pieces 
        int one, two;
        if (dp[i][y] != -1) one = dp[i][y];
        else one = phidias(i,y);
        if (dp[x-i][y] != -1) two = dp[x-i][y];
        else two = phidias(x-i, y);
        ans = min(ans, one + two);
    }
    for (int j = 1; j < y; j++){
        int one, two;
        if (dp[x][j] != -1) one = dp[x][j];
        else one = phidias(x,j);
        if (dp[x][y-j] != -1) two = dp[x][y-j];
        else two = phidias(x, y - j);
        ans = min(ans, one + two);
    }
    dp[x][y] = ans;
    return ans;
}

int main () {
    cin >> w >> h;
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++){
        int x ,y;
        cin >> x >> y;
        desired.push_back(Rect(x,y));
    }
    sort(desired.begin(), desired.end());

    // let dp[i][j] denote the min number of area wasted by splitting 
    // rectangle of length i, j
    dp[0][0] = 0;
    for (int i = 0; i <= w; i++){
        dp[i][0] = 0;
    }
    for (int j = 0; j <= h; j++){
        dp[0][j] = 0;
    }
    for (int i = 1; i <= w; i++){
        for (int j = 1; j <= h; j++){
            if (isDesired(i, j)) dp[i][j] = 0;
            else dp[i][j] = i * j;
            for (int x = 1; x < i; x++){
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j]);
            }
            for (int y = 1; y < j; y++){
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j - y]);
            }
        }
    }
    cout << dp[w][h];
}