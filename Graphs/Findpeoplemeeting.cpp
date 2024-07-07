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


struct Meeting {
    int x, y, time;
};
vector<int> father;
vector<int> height;
bool cmp (const Meeting &a, const Meeting &b) {
    return a.time < b.time;
} 
int find(int node) {
        if (father[node] != node) {
            father[node] = find(father[node]);
        }   
        return father[node];
    }
void unite(int u, int v){
    int rootU = find(u); // u is the smaller component
    int rootV = find(v); // v is the bigger componenet
    if (height[rootU] > height[rootV]) swap(rootU,rootV);
    
    father[rootU] = rootV;
    height[rootV] = max(height[rootV], height[rootU] + 1);
}
int main () {

        vector<vector<int>> meetings = {{3,4,2},{1,2,1},{2,3,1}};
        int firstPerson = 1;
        int n = 5;
   
        father = vector<int> (n,-1);
        height = vector<int> (n, 0);
        for (int i = 0; i < n; i++) father[i] = i;
        
        int m = meetings.size();
        unite(firstPerson, 0);
        vector<Meeting> v; 
        for (int i = 0; i < m; i++){
            if (meetings[i][2] > 0){
                Meeting temp;
                temp.x = meetings[i][0];
                temp.y = meetings[i][1];
                temp.time = meetings[i][2];
                v.push_back(temp);
            }
            
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++){
            Meeting m = v[i];
            unite(m.x,m.y);
        }
        cout << 0 << " ";
        for (int i = 0; i < n; i++){
            if (father[i] != i) cout << i << " ";
        }
        
  
    }
    


