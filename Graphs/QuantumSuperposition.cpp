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
const int N = 1000;

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
    int n1,n2,m1,m2;
    cin >> n1 >> n2 >> m1 >> m2;
    idx = n1-1;
    vector<int> adj1[N];

    for (int i = 0; i < m1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj1[a].push_back(b);
    }
    for (int i = 0; i < n1; i++){
        if (!entered[i]) ts(i);
    }
    vector<int> tsort1 = tsort;
    tsort = vector<int>(n2,0);
    for (int i = 0; i < n2; i++){
        entered[i] = false;
        exited[i] = false;
    }
    
    for (int i = 0; i < n2; i++){
        adj[i] = {};
    }
    for (int i = 0; i < m2; i++){
        int a,b;
        cin >> a >> b;

        a--;
        b--;
        adj[a].push_back(b);
    }
    idx = n2-1;
    for (int i = 0; i < n2; i++){
        if (!entered[i]) ts(i);
    }

    // tsort = tsort2 
    vector<set<int>> dp1; // dp[i] represents all possible steps to reach node i 
    for (int i = 0; i < n1; i++) {
        set<int> s; 
        dp1.push_back(s);
    }
    dp1[0].insert(0);
    for (int i = 0; i < n1; i++){
        int u = tsort1[i];
        for (auto v: adj1[u]){
            for (auto k: dp1[u]){
                dp1[v].insert(k + 1);
            }
        }
    } 
    vector<set<int>> dp2;   
     for (int i = 0; i < n2; i++) {
        set<int> s; 
        dp2.push_back(s);
    }
    dp2[0].insert(0);

    for (int i = 0; i < n2; i++){
        int u = tsort[i];
        for (auto v: adj[u]){
            for (auto k: dp2[u]){
                dp2[v].insert(k + 1);
            }
        }
    } 
    const int M = 2001;
    bool ans[M]= {false};
    for (auto i: dp1[n1-1]){
        for (auto j: dp2[n2-1]){
            ans[i+j] = true;
        }
    }
    int q; cin >> q;
    while (q--) {
        int a; cin >> a;
        if (ans[a]) cout << "Yes";
        else cout << "No";
        cout << "\n";

    }

}