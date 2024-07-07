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

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        map<char, int> m;
        for (auto c: s){
            m[c]++;
        }
        int even = 0;
        int odd = 0;
        for (auto const& [key,val]: m){
            if (val >= 2) even ++;
            else odd++;
        }
        if (even > 1) {
            cout << "YES";
        } else cout << "NO";
        cout << "\n";
    }
}