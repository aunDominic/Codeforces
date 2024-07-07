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

int main (){
    string s; 
    cin >> s;
    int n = s.size();
    int l = 0; 
    int r = 1;
    vector<int> p(n,0);
    int ans = 0;
    for (int i = 1; i < n; i++){
        // (l+r)/2 is the midpoint of the current palindrome

        // Once i exceeds the right side of the palindrome 
        // we need to construct a new current palindrome 
        if (i >= r){
            int left = i-1;
            int right = i+1;
            while (left >= 0 && right < n){
                if (s[left] == s[right]) p[i]++;
                else break;
                left--;
                right++;
            }
            l = left;
            r = right;
        }

      
        // Otherwise we can use previous calculations
        // j is the mirror of i
        else {
            int j = l + r - i; 
            p[i] = max(0, min(p[j], j - l));
        }
        ans = max(ans, 2 * p[i] + 1);
    }
    cout << ans;
}