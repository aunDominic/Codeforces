#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


const int N = 100000;
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
    if (isCycle){
        cout << "IMPOSSIBLE";
    }
    else {
        for (int i = 0; i < n; i++){
            cout << ts[i]+1 << " ";
        }
    }
}