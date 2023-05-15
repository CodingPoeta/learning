/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_a = 0;
        int sz = height.size();
        int max_h = 0;

        for (int i = 0, j = sz - 1; i < j; ) {
            int h =  min(height[i],height[j]);
            if (h > max_h) {
                max_h = h;
                max_a = max(max_a, h * (j-i));
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max_a;
    }
};
// @lc code=end

