#include "bits/stdc++.h"
#include <iostream>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // We need to simulate merging the two arrays in a sorted order
        // Obviously, we want to achieve this in a smart way. 
        // In the merged array, it will have length n + m, so its median is at (n+m) / 2, if odd
        // In the merged array, there will be l_1 + l_2 elements to the left of its median
        // Clearly l_1 + l_2 = (n+m)/2
        // so we can guess l_1, and calculate l_2 accordingly
        // cases:
        // l_1 < l_2 : 
        //      
        // l_2 < l_1 : 
        // n + m = 7
        // (n + m) / 2 = 3 , 4th element 
        // n + m = 8 , (n+m) / 2 = 4 -> 5th element 
        
        int n = nums1.size();
        int m = nums2.size(); 
        if (n > m) return findMedianSortedArrays(nums2,nums1);
        if (n == 0){
            if (m % 2 == 0) return (nums2[m/2] + nums2[m/2 - 1]) / 2.0;
            else return nums2[m/2];
        }

        int l = 0;
        int r = n;
        // treat left as the number of elements 
        int left = (n + m) / 2; // if odd, left does not include the middle
        // even, left includes the left middle 

        while (l <= r){
            int m1 = (l + r) / 2;
            int m2 = left - m1;
            // we want l1 or l2 to be the first median
            cout << "HERE";
            
            int l1;
            if (m1 - 1 >= 0) l1 = nums1[m1-1];
            else l1 = INT_MIN;
            int l2;
            if (m2-1 >= 0) l2 = nums2[m2-1];
            else l2 = INT_MIN;
            cout << m1 << " " << m2 << "\n";
            int r1;
            if (m1 < n) r1 = nums1[m1];
            else r1 = INT_MAX;
            int r2;
            if (m2 < m) r2 = nums2[m2];
            else r2 = INT_MAX;

            


            // if l_1 > r_2 ,then left side is greater than half 
            if (l1 > r2) {
                r = m1-1; 
                continue;
            } 
            // if l_2 > r1, then left side is greater than half
            else if (l2 > r1){
                l = m1+1;
                continue;
            }
            
            // l1 <= r2 && l1 <= r1
            // l2 <= r1 && l2 <= r2
            // then we have the right amoutn on left side
            
            int maxl = max(l1, l2);
            int minr = min(r1,r2);
            if ((n+m) % 2 == 1) {
                return max(maxl, minr);
            }
            return (maxl + minr) / 2.0;

        }
        return 0;
    }
int main(){
    vector<int> nums1 = {1};
    vector<int> nums2 = {2,3,4};
    // 
    cout << findMedianSortedArrays(nums1, nums2);
}