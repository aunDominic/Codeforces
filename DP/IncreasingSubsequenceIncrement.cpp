#include "bits/stdc++.h"
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i =0 ; i < n; i++) cin >> v[i];
    // let dp[i] = j where j is v[i] = v[j] + 1, i, j < n are indices 
    // if v[j] has duplicates then the more recent j is the better answer 

    vector<int> parent(n, -1);
    vector<int> len(n, 1);
    int cnt = 1;
    int start = 0;
    map<int, int> visited;
    for (int i = 0; i < n; i++){
        visited[v[i]] = i;
        if (visited.count(v[i] - 1) > 0){
            parent[i] = visited[v[i] - 1];
            len[i] = len[visited[v[i] - 1]] + 1;
            if (len[i] > cnt){
                cnt = len[i];
                start = i;
            }
        }
    }
    cout << cnt << '\n';
    vector<int> ans;
    while (start != -1){
        ans.push_back(start);
        start = parent[start];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
}