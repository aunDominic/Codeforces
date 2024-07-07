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

int main () {
    long long n = 178;
    bitset<50> b = bitset<50>(n);
    for (int i = 49; i >= 0; i--) cout << b[i];

    bool rule = false;
    while (b != 0){
        if (rule) b[0] = !b[0];
        else {
            bool firstOne = false;
            for (int i = 0; i <= 49; i++){
                if (firstOne){
                    // flip ith bit such that i+1 is one, and i+2 onwards is zero
                    b[i] = !b[i];
                    break;
                }
                if (b[i] == 1) firstOne = true;
            }
        }
        cout << (int)(b.to_ulong());
        rule = !rule;
        cout << "\n";
    }



    
}