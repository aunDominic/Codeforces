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
 
struct Project{
    long long s, e, w;
    Project (long long s, long long e, long long w):
     s(s), e(e), w(w){}
 
    bool operator< (const Project &other) const{
        return this-> e < other.e;
     }
};

bool cmp (const Project &a, const Project &b){
    if (a.e == b.e) return a.w > b.w;
    return a.e < b.e;
}
 
int main(){
    int n;
    cin >> n;
 
   
    vector<Project> v;
    v.push_back(Project(0,0,0));
    for (int i = 0; i < n; i++){
        int a, b, p;
        cin >> a >> b >> p;
        v.push_back(Project(a,b,p));
    }
    sort(v.begin(), v.end());
 
    // let dp[i] denote the maximum money earned 
    // from attending a subset of the first i projects 
    
    vector<long long> dp(n+1,0); 
    // let p[j] denote the maximum index 
    // at some iteration i 
    // we want to decide whether to include Project i 
    // if we include Project i,
    // it is only possible from all other projects j such that
    // j.end < i.start
    // it is best if we consider the largest j such that above is true
    // as does considers a potentially larger subset.
    dp[1] = v[1].w;
    for (int i = 1; i<= n; i++){
        Project t = Project(0,v[i].s, 0);
        // the first project j such that 
        // j.end >= i.start
        int j = lower_bound(v.begin(), v.end(), t) - v.begin()-1;
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], v[i].w + dp[j]);
    }
    cout << dp[n];
 
}