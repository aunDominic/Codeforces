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
    // odd palindromes
    string s;
    cin >> s;
    string ans = "";
    ans += s[0];
    for (int i = 0; i < s.size(); i++){
        string res = "";
        res += s[i];
        int l = i - 1;
        int r = i + 1;
        string left = "";
        string right = "";
        while (l >= 0 && r < s.size()){
            if (s[l] == s[r]) {
                left += s[l];
                right += s[r];
            } else {
                break;
            }
            l--;
            r++;
        }
        reverse(left.begin(), left.end());
        res = left + res + right;
        

        if (res.size() > ans.size()) ans = res;
    }
    // even palindromes 
    for (int i = 0; i < s.size()-1; i++){
        string res = "";
        if (s[i] != s[i+1]) continue;
        res += string(1, s[i]) + string(1,s[i+1]);
        int l = i - 1;
        int r = i + 2;
        string left = "";
        string right = "";
        while (l >= 0 && r < s.size()){
            if (s[l] == s[r]) {
                left += s[l];
                right += s[r];
            } else {
                break;
            }
            l--;
            r++;
        }
        reverse(left.begin(), left.end());
        res = left + res + right;
        if (res.size() > ans.size()) ans = res;
    }
    cout << ans;
}

