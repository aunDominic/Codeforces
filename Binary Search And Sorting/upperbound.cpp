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

// Find the maximum x such that f(x) is true
// f(x) is a monotonic increasing function
// if f(y) true, then all x <= y is true 
// if f(y) false, then all x >= y is false

// To solve 1, we find the first element su     ch that f(x) is false
// Then the answer is just the element before that
// Check if its within bounds of l and r
int upperbound(int l, int r, function<bool(int)> f){
    // return l-1 if none of the elements in [l,r] works
    l--;
    while (l < r){
        int mid = l + (r - l + 1) / 2; // rounded up
        if (f(mid)){
            // if mid works, then all x <= mid works
            // so set l = mid
            // l is the highest known element so far that satisfies f
            l = mid;
        } else{
            // if mid doesnt work, then all x >= mid doesnt work
            // we want all elements [l, r] to satisfy f
            r = mid - 1;
        }
    }
    return l;
}

// Find the minimum x such that f(x) is satisfied
// f(x) is monotonically decreasing
// if y works, then all x >= y works 
// if y doesnt work, then all x <= y doesnt work
int lowerbound(int l, int r, function<bool(int)> f){
    r--;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (f(mid)){
            // If mid works, then all mid >= x works
            // we want the smallest 
            // mid is the smallest known element so far that works
            r = mid;
        } else {
            // mid doesnt work
            // then all mid <= x doesnt work
            // we want [l,r] to work 
            l = mid + 1;
        }
    }
}