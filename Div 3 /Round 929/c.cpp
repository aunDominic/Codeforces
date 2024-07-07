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

int main () {
    int t;
    cin >> t;
    while (t--){
        int a,b,l;
        cin >> a >> b >> l;
        int maxx = 0;
        int maxy = 0;
        int tl = l;
        while (tl % a == 0){
            maxx++;
            tl /= a;
        }
        tl = l;
        while (tl % b == 0){
            tl /= b;
            maxy++;
        }
        set<int> s;
        for (int i = 0; i <= maxx; i++){
            for (int j = 0; j <= maxy; j++){
                int product = pow(a, i) * pow(b, j);
                if (l % product == 0) s.insert(l / product); 
            }
        }
        cout << s.size() << "\n";
    }
}