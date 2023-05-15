/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int p1 = 0, p2 = 0;

        while (1) {
            if (p1 == m) return nums2[ p2 + k - 1 ];
            if (p2 == n) return nums1[ p1 + k - 1 ];
            if (k == 1) return min(nums1[p1], nums2[p2]);

            int np1 = min(p1 + k/2 - 1, m - 1);
            int np2 = min(p2 + k/2 - 1, n - 1);
            int v1  = nums1[np1];
            int v2  = nums2[np2];

            if (v1 <= v2) {
                k -= np1 - p1 + 1;
                p1 = np1 + 1;
            } else {
                k -= np2 - p2 + 1;
                p2 = np2 + 1;
            }
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        return (m + n)%2 ? findKth(nums1, nums2, (m+n)/2+1):
                           (findKth(nums1, nums2, (m+n)/2) + findKth(nums1, nums2, (m+n)/2+1)) / 2.0;
    }
};
// @lc code=end

