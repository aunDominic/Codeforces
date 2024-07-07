#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum ; // Initialize to minimum long long value
        map<int, int> m; 
        int n = nums.size();
        vector<long long> pf(n + 1, 0);
        bool isSum = false;
        
        // Create prefix sum array
        for (int i = 0; i < n; i++) {
            pf[i + 1] = (long long)nums[i] + pf[i];
        }

        for (int i = 0; i < n; i++) {
             // abs(nums[i] - j) = k
            // Two cases: 
            // nums[i] - j = k -> nums[i] - k = j
            // j - nums[i] = k -> nums[i] + k = j
            if (m.count(nums[i] - k)) {
                int j = m[nums[i] - k];
                if (!isSum) {
                    sum = pf[i + 1] - pf[j];
                    isSum = true;
                }
                sum = max(sum, pf[i + 1] - pf[j]);
            }
            if (m.count(nums[i] + k)) {
                int j = m[nums[i] + k];
                if (!isSum) {
                    sum = pf[i + 1] - pf[j];
                    isSum = true; 
                }
                sum = max(sum, pf[i + 1] - pf[j]);
            }
            // Store the index of the current element
            m[nums[i]] = i;
        }
        log10()
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> v = {-1,3,2,4,5};
    long long ans = sol.maximumSubarraySum(v, 3);
    cout << ans << endl;
}
