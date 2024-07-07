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

using namespace std;
const int N = 1e5;

bool entered[N] = {false};
bool exited[N]  = {false};

int idx;
vector<int> tsort(N,0);
vector<int> adj[N];
void ts (int u){
    entered[u] = true;

    for (auto v: adj[u]){
        if (!entered[v]){
            ts(v);
        }
        else if (!exited[v]){ //cycle
            return;
        }
    }

    exited[u] = true;
    tsort[idx] = u;
    idx--;

}
int main() {
    int n; cin >> n;
    idx = n-1;
    int m; cin >> m;

    vector<int> parent(n, -1);

    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        parent[b] = a;
    }
    for (int i = 0; i < n; i++){
        if (!entered[i]) ts (i);
    }
    long long mod = 1e9 + 7;
    vector<long long> dp(n,0);
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        int u = tsort[i];
        for (auto v: adj[u]){
            dp[v] += (dp[u] % mod);
            dp[v] %= mod;
        }

    }
    cout << dp[n-1] % mod;

}