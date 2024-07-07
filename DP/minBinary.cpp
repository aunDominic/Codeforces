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


const long long N = 1e6;
bool visited[N];

long long toDecimal(vector<int> &bits){
    long long ans = 0;
    for (int i = bits.size()-1; i >= 0; i--){
        ans += bits[i] * pow(2, i);
    }
    return ans;
}

long long minBinary(vector<int> bits){
    long long dec = toDecimal(bits);
    if (dec == 0) return 0;
    if (visited[dec]) return LLONG_MAX-10;
    visited[dec] = true;
    long long ans = LLONG_MAX;
    int n = bits.size();
    bool firstOne = false;
    for (int i = n-1; i >= 0; i--){
        if (firstOne){
            // flip ith bit such that i+1 is one, and i+2 onwards is zero
            bits[i] = !bits[i];
            ans = min(ans, 1 + minBinary(bits));
            bits[i] = !bits[i];
            break;
        }
        if (bits[i] == 1) firstOne = true;
    }

    // flip rightmost bits
    bits[n-1] = !bits[n-1];
    ans = min(ans, 1 + minBinary(bits));
    return ans;
}

int main (){
    int n;
    cin >> n;
    string b = bitset<50>(n).to_string();

    vector<int> bits; 
    bool found1 = false;
    for (int i = 0; i < b.size(); i++){
        if (b[i] == '1') found1 = true;
        if (found1) {
            bits.push_back(b[i] - '0');
        } 
    }
    for (int i = 0; i < bits.size(); i++){
        cout << bits[i];
    }
    cout << "\n";

    cout << minBinary(bits);


}