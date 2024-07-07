#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main(){
    int n; cin >> n; // Numbers 
    int k; cin >> k; // Number of subarrays

    vector<long long> v(n,0);
    for (int i = 0; i < n; i++) cin >> v[i];

    // Every element must belong to a subarray.
    // Before looping thru the array, we don't know where each element should belong to.
    // IDEA 1: Loop thru array, after processing element, we decide which group it should belong to. 
    // We want to minimise the maximum sum. So we should keep track of the maximum sum.
    // We will need to construct subarrays to find the sum of each subarray. 
    int mx = 0;
    
    // Suppose we are at the ith element, and we all j < i elements are optimally divided into subarrays such that 
    // mx is at a minimum. 
    // At the ith element, it can either belong to the previous subarray, or we create a new subarray with that element only. 
    // First choice increases the sum of previous array. Second choice creates a new sum. Can we greedily decide this? 

    // There is a limit on the number of subarrays. 
    // We can greedily create a new subarray everytime. 
    // k = 3
    // 1 2 3 4 5 6 7 8 9 10 


    // Dealing with sums, could easily use a prefix sum, then only 2 endpoints is required to calculate the sum of the subarray.
    // If iterating over the prefix sum array, then the problem becomes finding k+1 indices such that with a minimal maximum sum. 
    // IDEA 2: In an optimal arrangement of k subarrays, eg 2 subarrays, these subarrays must also be one of the subarrays in an 
    // optimal arrangement of k+1 subarrays. 

    // k = 2 transition to k = 3, then one of the existing subarrays must be divided further. 
    // Suppose the array is divided optimally into k subarrays. -> we have a minimal maximum sum. 
    // Now we can further divide the array into k+1 subarrays. 
    // Claim: we use the current k subarrays, and divide one out of the k subarrays into 2. we will divide the maximal one. 
    // Suppose we dont use the current k subarrays, ie we have a different optimal arrangement of k subarrays.
    // In k+1, we must divide the array with maximal sum. Since we can make an additional subarray, we can always reduce the sum of any subarray.
    // Obviously we must pick the subarray with maximal sum, else our answer wouldn't decrease (but we always can). 
    // so we pick the a maximal sum with arrangement A2, mx2 >= mx1 (as it was not optimal)
    // and we optimally divide this subarray into 2, creating a new max sum of n2. 

    // LMAO

    // Binary search on the answer space, check if its possible to achieve the answer 
    // If we achieve an answer of x, then we can also achieve an answer of y > x using the same amount of divisions. 
    // if x true, then all y > x true, so f is monotonically decreasing? 
    // so we wanna find the minimum x such that f is true. 
    long long lo = 0;
    long long hi = 2 * 1e5 * 1e9 + 1;   

    auto f = [n, k, v](long long x) -> bool{
        int cnt = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++){
            if (sum + v[i] <= x) {
                sum += v[i];
            } else {
                sum = v[i];
                if (v[i] > x) return false;
                cnt++;
                if (cnt > k) return false;
            }
        }
        return true;
    };

    while (lo < hi){
        long long mid = lo + (hi - lo) / 2;
        // if mid works then, all numbers after mid works.
        if (f(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
}