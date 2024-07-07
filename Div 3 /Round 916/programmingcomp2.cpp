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


int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> adj[n]; 
        for (int i = 0; i < n-1; i++){
            int a;
            cin >> a;
            a--;
            adj[a].push_back(i+1);
        }
        vector<int> depth(n,0);
        // perform bfs to get the number of nodes in each depth;
        queue<int> q;
        q.push(0);
        int d = 0;
        while (!q.empty()){                    
            queue<int> tmp;
            while(!q.empty()){
                int u = q.front();
                for (auto v: adj[u]){
                    tmp.push(v);
                }
                depth[d]++;
                q.pop();    
            }
            q = tmp;
            d++;
        }    
        // for (int i = 0; i < n; i++){
        //     cout << depth[i] << " ";
        // }
     
        int ans = 0;
        int unpaired = 0;
        for (int i = n-1; i >= 1; i--){
            if (depth[i] > 1){
                int x = min(unpaired, depth[i] - 1);
                unpaired -= x;
                depth[i] -= x;
                ans += x;
            }
            ans += depth[i] / 2;
            depth[i] %= 2;
            unpaired += depth[i];
        }

        // WHY DOES IT WORK
        
        cout << ans << "\n";
    }
}