 #include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10;
vector<int> adj[N];
vector<int> child(N,0); // child[i] contains the number of children of node i 
void dfs (int u){
    for (auto v : adj[u]){
        dfs(v); 
        child[u] += child[v];
    }
    child[u]++;
}

int main(){
    int t; 
    cin >> t; 
    while (t--){
        int n; 
        cin >> n;
        for (int i = 0; i < n; i++) adj[i] = {};
        child = vector<int>(N,0);
        for (int i = 1; i < n; i++){
            int a; 
            cin >> a;
            a--;
            adj[a].push_back(i);
        }
        dfs(0);
        priority_queue<int> pq;
        int ans = 0;
        for (int i = 0; i < adj[0].size(); i++)pq.push(child[adj[0][i]]);

        while (!pq.empty() && pq.size() > 1){ // at least 2 subtrees
            int x = pq.top(); pq.pop(); //subtree with largest amount of children
            int y = pq.top(); pq.pop();
            x--; y--;
            ans++;
            if (x > 0) pq.push(x);
            if (y > 0) pq.push(y);
        }
        cout << ans << "\n";
        

        

    }
}