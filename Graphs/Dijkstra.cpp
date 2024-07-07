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


const int INF = 1e8;
const int N = 1e5;
vector<pair<int,int>> adj[N]; 

bool visited[N] = {false};
vector<int> dist(N,INF);
int main(){

    priority_queue<pair<int,int>, vector<int>, greater<int>> pq;

    pq.push(0);

    dist[0] = 0;
    while (!pq.empty()){
        auto [v,w] = pq.top(); pq.pop();

        for (auto k: adj[v]){
            pq.push(k);
        }

    }

}