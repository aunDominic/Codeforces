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
bool exited[N] = {false};
vector<pair<int,int>> adj[N];
int ts[N];
int idx;
void dfs(int u){
    entered[u] = true;

    for (auto [v, w]: adj[u]){
        if (!entered[v]) {
            dfs(v);
        }
        else if (!exited[v]) {
            // there is a cycle;
            return;
        }
    }
    exited[u] = true;
    ts[idx] = u;
    idx--;
}
int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    idx = n-1;

    vector<long long> v;
    for (int i = 0; i < n; i++){
        int a; cin >> a; 
        v.push_back(a);
    }
    for (int i = 0; i < c; i++){
        long long a, b, x;
        cin >> a >> b >> x;
        a--;b--;
        adj[a].push_back({b,x});
    }
    for (int i = 0 ; i < n; i++){
        if (!entered[i]) dfs(i);
    }
    for (int i = 0; i < n; i++){
        int u = ts[i];
        for (auto [b, w] : adj[u]){
            v[b] = max(v[u] + w, v[b]);
        }
    }
    for (int i = 0; i < n; i++){
        cout << v[i] << "\n";
    }
}