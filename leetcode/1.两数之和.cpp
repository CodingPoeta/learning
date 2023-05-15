/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (auto j = mp.find(target - nums[i]); j != mp.end()) {
                return {j->second, i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};
// @lc code=end

