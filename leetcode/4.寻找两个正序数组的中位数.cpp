/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int sz1 = nums1.size();
        int sz2 = nums2.size();
        int left_p = 0, right_p = sz1;
        int mid1 = 0, mid2 = 0;

        // nums1 0, 1... div1 - 1 | div1...m-1
        // nums2 0, 1... div2 - 1 | div2...n-1
        // div1 + div2 == (sz1+sz2)/2
        while (left_p <= right_p) {
            int div1 = (left_p + right_p) / 2;
            int div2 = (sz1+sz2)/2-div1;

            // cout << div1 << " " << div2 << endl;

            int lv1 = (div1 == 0 ? INT_MIN : nums1[div1-1]);
            int rv1 = (div1 == sz1 ? INT_MAX : nums1[div1]);
            int lv2 = (div2 == 0 ? INT_MIN : nums2[div2-1]);
            int rv2 = (div2 == sz2 ? INT_MAX : nums2[div2]);

            mid1 = max(lv1, lv2);
            mid2 = min(rv1, rv2);
            if (lv2 > rv1) {
                left_p = div1+1;
            } else if (lv1 == rv2){
                return lv1;
            } else if (lv1 > rv2) {
                right_p = div1-1;
            } else break;
        }
        return (sz1 + sz2)%2 ? mid2 : (mid1 + mid2)/2.0;
    }
};
// @lc code=end

