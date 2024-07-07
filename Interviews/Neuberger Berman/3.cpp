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

float evenProb(float p, int n) {
    long double q = 1 - p;
    long double prev = pow(q, n);
    long double ans = prev;
    
    for (int i = 2; i <= n; i+= 2){
        prev = prev * p * p / q / q / i / (i-1) * (n-i+2) * (n-i+1); 
        ans += prev;
    }    
    return ans;
    
}
int main () {
    double prev = 0.5;
    for (int i = 0; i < 1e8; i++) prev *= 0.5;
    cout << prev;
    cout << evenProb(0.5, 100000000);
}