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



class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &secret, vector<bool> &visited){
        if (visited[u]) return;
        visited[u] = true;

        for (auto v: adj[u]){
            secret[v] = true;
            dfs(v, adj, secret, visited);
        }    
    }
    void topsort(int u, vector<bool> &entered, vector<bool> &exited){
        entered[u] = true;

        
        exited[u] = true;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> secret(n,false);
        secret[0] = true;
        secret[firstPerson] = true;
        map<int,vector<vector<int>>> adjTime;
        int m = meetings.size();
        for (int i = 0; i < m; i++){
            int x = meetings[i][0];
            int y = meetings[i][1];
            int t = meetings[i][2];
            if (!adjTime.count(t)){
                adjTime[t] = vector<vector<int>> (n, vector<int>());
            }
            adjTime[t][x].push_back(y);
            adjTime[t][y].push_back(x);
        }
        for (auto const &x: adjTime){
            for (auto )
        }

}
};
