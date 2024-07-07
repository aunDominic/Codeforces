#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


const int N = 1e5;
bool entered[N] = {false};
bool exited[N]  = {false};
bool isCycle = false;
int i;
int ts[N] = {0};


vector<int> adj[N];
void dfs(int u){
    entered[u] = true;

    for (auto v : adj[u]){
        if (!entered[v]) {
            dfs(v);
        }
        else if (!exited[v]) {
            // there is a cycle;
            isCycle = true;
            break;
        }
    }
    exited[u] = true;
    ts[i] = u;
    i--;
}

int main(){
    // freopen("flight.in", "r", stdin);
    // freopen("flight.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    i = n-1;

    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    for (int i = 0 ;i < n; i++){
        if (!entered[i]){
            dfs(i);
        }
    }
    vector<int> dp (n,0); // dp[i] is the maximal route to reach city i 
    dp[0] = 1;
    vector<int> prev(n,0);
    int start = -1;
    int end = -1;
    for (int i = 0; i < n; i++){
        if (ts[i] == 0){
            start = i;
        }
        if (ts[i] == n-1) {
            end = i;
        }
    }


    for (int i = start; i <= end; i++){
        int u = ts[i];
        for (auto v: adj[u]){
            if (dp[v] < dp[u] + 1){
                dp[v] = dp[u] + 1;
                prev[v] = u;
            }
        }
    }
    if (dp[n-1] == 0) cout << "IMPOSSIBLE";
    else {
        cout << dp[n-1] << "\n";
        stack<int> ans;
        int curr = n-1;
        while (curr != 0){
            ans.push(curr);
            curr = prev[curr];
        }
        ans.push(0);
        for (int i = 0; i < dp[n-1] ; i++){
            cout << ans.top()+1<< " ";
            ans.pop(); 
        }
        

    }
  
    

}