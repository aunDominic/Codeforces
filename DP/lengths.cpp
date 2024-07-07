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

int main(){
    int n = 6;
    // C[k] = cost to buy wood of length k
    vector<int> c = {0,5,6,100,100,100,100};
    // M[i] = minimum cost to buy combination of woods whose lengths sum up to i
    // Initialise to infinity, 1-indexed.
    vector<int> m(n+1, INT_MAX);
    m[0] = 0;
    // Answer given 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            m[i] = min(m[i], c[j] + m[i-j]);

            // the solution to m[i] will always consist of say k pieces of wood bought
            // one can always one of wood k, and find the min cost to buy the remaining length
            // the remaining length is smaller than i, so we its precomputed
            
        }
    }

    for (int i = 1; i <= n; i++) cout << m[i] << " "; 


    
}