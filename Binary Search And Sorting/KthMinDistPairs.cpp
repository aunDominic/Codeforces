#include "bits/stdc++.h"
#include <iostream>
using namespace std;

 int smallestDistancePair(vector<int>& nums, int k) {
        // binary search the answer
        // let distance d be given, 
        // we want to find how many distances are smaller than it, let this number be k'
        // if k' < k, then we increase d 
        // if k' > k, then we decrease d 
        // so we want to find the minimum distance such that k' >= k

        // we use two pointers to find the number of distances smaller than d 
        // let a[l:r] such that a[r] - a[l] <= d and r max
        // every time you move r, there are r - l - 1 elements before it
        // each of these elements can contribute to a distance 
        sort(nums.begin(), nums.end());

        auto f = [nums, k](int d) -> bool{
            int n = nums.size();
            int l = 0;
            int r = 0;
            int cnt = 0;
            while (l <= r){
                while (r < n && nums[r] - nums[l] <= d){
                    r++;
                    cnt += (r - l - 1);
                }
                l++;
            }
            return cnt >= k;
        };

        int lo = 1;
        int hi = 6;
        while (lo < hi){
            int mid = lo + (hi - lo) / 2;
            if (f(mid)){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;

    }

int main(){
    vector<int> v = {10,7,6,1,5,4,9,8};
    cout << smallestDistancePair(v, 15);
}