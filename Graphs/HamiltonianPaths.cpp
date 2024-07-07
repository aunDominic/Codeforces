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

const int N = 20;
long long flights[(1 << N)][N] = {0};


bool cmp (const pair<set<int>,int> &a, const pair<set<int>,int> &b){
    return a.first.size() < b.first.size();
}
int main() {
    long long mod = 1e9 + 7;
    int n, m; cin >> n >> m;
    int adj[N][N] = {0};
    for (int i = 0; i < m; i++){
        int a,b ;
        cin >> a >> b;
        a--;b--;
        adj[a][b] += 1;
    }
    // int start = 0;
    for (int i = 0; i < n;i++){
        if(adj[0][i]){
            flights[0][i] = adj[0][i]; // there exist 
        }
    }
    vector<pair<set<int>,int>> subsets;
    for (int i = 1; i < (1 << n-1); i++){ 
        // loop thru 2^n-1 nonempty subsets
        // i representsthe subset 
        // i = 0 -> 000
        // i = 1 -> 001
        // i = 2 -> 010
        // i = 3 -> 011
        // i = 4 -> 100
        // i = 5 -> 101
        // i = 6 -> 110
        // i = 7 -> 111
        // i = 8 -> 1000
        // i = 9 -> 1001 
        // i = 10 -> 1010
        // i = 11 -> 1011
        // i = 12 -> 1100
        // k = {1, 2, .. , N}
        // 2 ^ k -> subsets with 1 elem
        // 2 ^ k + 2 -> subsets with 2 elem , 3,5,6,9,10,12
        // 2 ^ k + 4 ->  


        // u dont have to go thru subsets in increasing order of size?
        // We can iterate subsets according to its natural ordering.
        if (i & 1 == 1) continue; // look for subsets not containing the start
        for (int j = 1; j < n; j++){ // look for nodes not = start 
            if ((i  &  (1 << j)) == 0){ // look for nodes not in the subset
                flights[i][j] = 0;
                for (int u = 1; u < n; u++){ 
                    // we want to add node j to the path
                    // node j has to connect from some node u in the subset
                    // so if theres an arc from u to j, then we can create a path ending at u
                    // Check that defintion of dp is preserved at each transition
 
                    // flights[i - (1 << u)[u]] is the number of H walk from start, using intermediary nodes from subset (i - (1<<u)) ending at u
                    // we then transition from node u to node j
                    // so we end node j
                    // then flights[_][j] () the j part is preserved.
                    // u is part of subset i
                    // therefore the path of flights[i - 1 << u][u] is the subset i 
                    // so we have used the subset i as intermediary nodes, and ended at nodes j 
                    // we have preserved the dp definition.
                    if ((i & (1 << u)) != 0){
                        flights[i][j] += ((flights[i - (1 << u)][u]) % mod * (adj[u][j]) % mod) % mod; 
                    }
                    // i - (1 << u) represents the subset not containing u 
                }
            }
        }
    }
    // flights[i][j] is defined to be the number of hamiltonian walks from start, using all intermediary nodes from subset i, ending at node j 
    cout << flights[(1 << n-1) -2][n-1] % mod;


}