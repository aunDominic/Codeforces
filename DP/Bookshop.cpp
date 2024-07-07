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
    int n,x;
    cin >> n >> x;
    
    vector<int> price(n+1,0);
    vector<int> pages(n+1,0);
 
    for(int i = 0; i < n;i++)
    {
        cin >> price[i+1];
    }
    for(int i = 0 ; i < n; i++){
        cin >> pages[i+1];
    }
 
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));


    // when the total budget increases, we could choose any of the books to buy. 
    // dp[j][i] = the maximum number of pages using a combination of the first i books and up to total price j

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j]; // not using the ith book
            
            // we first take the solution using a combination of the first i-1 books up to price j
            // we can take for all j, price j, because it has already been computed
            // for all possible budgets, we pick the best combination of books up to i 
            if (j - price[i] >= 0) {
                // we consider picking book i
                
                dp[i][j] = max(dp[i][j], dp[i-1][j - price[i]] + pages[i]);
            }
        }
    }
    cout << dp[n][x];
    
}