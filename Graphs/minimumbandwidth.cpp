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

const int N = 10;
int band[N][N];
int nextt[N][N];
int main(){
    int n; cin >> n;
    int m; cin >> m;
    int q; cin >> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            band[i][j] = 0;
            nextt[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++){
        int a, b, w;

        cin >> a >> b >> w;

        a--;b--;
        band[a][b] = w;
        nextt[a][b] = b;
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = i+1; j< n; j++){
                int old = band[i][j];
                band[i][j] = max(band[i][j], min(band[i][k], band[k][j]));
                if (old != band[i][j]){
                    nextt[i][j] = nextt[i][k];
                }
            }
        }
    }

  
    while (q--){
        int a,b; cin >> a >> b;
        a--;b--;
        cout << band[a][b] << "\n";
        cout << a+1 << " "; 
        while(a != b){
            if (nextt[a][b] == -1) {
                cout <<"no such path\n";
                break;
            }
            cout << nextt[a][b]+1 << " ";
            a = nextt[a][b];
        }
    }

}

if (true){
    do 
        xorx

        x
        x
        x
        x

}
else {
    
}