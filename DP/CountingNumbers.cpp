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

bool isNotCon (long long x){
    vector<int> v;
    for (int d = 1; d <= log10(x) + 1; d++){
        int div = pow(10,d);
        int digit = (x % div) / (div / 10);
        v.push_back(digit);
    }
    for (int i = 1; i < v.size(); i ++){
        if (v[i] == v[i-1]) return false;
    }
    return true;
}

int main (){
    long long a, b;
    cin >> a >> b;



    // let dp[n][d] denote the number of integers of length n ending with digit d 
    // such that no two adjacent digits are the same.
    
    // then dp[n][d] = sum of dp[n-1][d'] for all d' != d;
    int l = 1;

    if (b > 0) l = log10(b) + 1;
    vector<vector<long long>> dp (l+1, vector<long long> (10, 0));

    for (int k = 0; k < 10; k++){
        dp[1][k] = 1;
    }

    for (int i = 2; i <= l; i++){
        for (int j = 0; j < 10;j++){
            
            for (int k = 0; k < 10; k++){
                long long count  = dp[i-1][k];
                if (j != k){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
    }
    long long ans = 0;

    // make the msb of a = msb of b
    long long dd;
    long long c = 0; 

    for (int d = log10(a) + 1; d >= 1; d--){
        int div = pow(10,d);
        int digitA = (a % div) / (div / 10);
        int digitB = (b % div) / (div / 10);
        c += digitB * pow(10,d-1);
        if (digitA != digitB) {
            dd = pow(10, d);
            break;
        }
    }
    long long d = 10;

    while (a < c){
        // let d = pow(10, x);
        // then digit is the xth digit of a
        int digitA = (a % d) / (d / 10);
        
        int i = log10(d);
        if (isNotCon(a / (d/10)))ans += dp[i][digitA];
        a += d/10;
        digitA = (a % d) / (d / 10);
        if (digitA == 0) {
            d *= 10;
            continue;
        }   
    }
    while (c != b){
        int digitC = (c % dd) / (dd / 10);
        int i = log10(dd);
        if (c + dd/10 <= b){
            if (isNotCon(c / (dd/10)))ans += dp[i][digitC];
            c += dd/10;
        } else {
            dd /= 10;
        }
    }

    if (isNotCon(b)) ans++;
    cout << ans;
}