class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        // let dp[i][2] be the 
        // minimum last number of a longest non decreasing subsequence of length i
        // where the last number 

        // 1 3 2 1 
        // 2 2 3 4
        // 1 2 2 4              dp[i][0]
        // 1 2 3 4               dp[i][1]
        // 5 6 7 8
        // 3 1 4 9
        vector<int> lis;

        int n = nums1.size();
        for (int i = 0; i < n; i++){
            auto it1 = upper_bound(lis.begin(), lis.end(), nums1[i]);
            auto it2 = upper_bound(lis.begin(), lis.end(), nums2[i]);
            if (it1 == lis.end() && it2 == lis.end()){
                lis.push_back(min(nums1[i], nums2[i]));
            }
            else if (it1 == it2){
                lis[it1 - lis.begin()] = min(nums1[i], nums2[i]);
            }
            else if (it1 == lis.end()){
                lis[it2 - lis.begin()] = nums2[i];
                lis.push_back(nums1[i]);
            }
            else if (it2 == lis.end()){
                lis[it1 - lis.begin()] = nums1[i];
                lis.push_back(nums2[i]);
            }
            else {
                lis[it2 - lis.begin()] = nums2[i];
                lis[it1 - lis.begin()] = nums1[i];
            }
            for (auto x : lis){
                cout << x << " ";
            }
            cout << '\n';
        }
        return lis.size();
    }
};