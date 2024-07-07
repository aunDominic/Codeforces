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

int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            sum += a;
            v.push_back(a);
        }
        int r = (sum % 3);
        if (r == 0) {
            cout << 0 << "\n"; 
        } else {
            int maxmoves = 3 - r;
            if (maxmoves == 1) cout << 1 << "\n";
            else {
                bool flag = false;
                for (int i = 0; i < n; i++){
                    if ((sum - v[i]) % 3 == 0){
                        cout << 1 << "\n";
                        flag = true;
                        break;
                    }
                }
                if (!flag){
                    cout << 2 << "\n";
                }
            }
        }
        


    }
}