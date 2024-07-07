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

struct Tower{
    int x,y, dmg;
    Tower(int x, int y, int dmg){
        this->x = x;
        this->y = y;
        this->dmg = dmg;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<char>> grid(n, vector<char> (m,'a'));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        vector<Tower> twr;
        for (int i = 0; i < k; i++){
            int a, b, c;
            cin >> a >> b >>c;
            twr.push_back(Tower(a,b,c));
        }
        // For every tower
        for (int i = 0; i < k; i++){
            // For every range
            for (int r = 1; r <= 71; r++){}
        }
    }
}
