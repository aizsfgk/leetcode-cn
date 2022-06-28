//给定一个非空的正整数数组 nums ，请判断能否将这些数字分成元素和相等的两部分。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：nums 可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：nums 不可以分为和相等的两部分
// 
//
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
//
// 
//
// 注意：本题与主站 416 题相同： https://leetcode-cn.com/problems/partition-equal-subset-
//sum/ 
// Related Topics 数学 字符串 模拟 👍 47 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    bool ans = false;
    void backtracking(const vector<int> &nums, int idx, int target) {

        if (target == 0) {
            ans = true;
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i=idx; i<nums.size(); i++) {
            backtracking(nums, i+1, target-nums[i]);
        }
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0 ) return false;

        int target = sum / 2;

        sort(nums.begin(), nums.end());

        backtracking(nums, 0, target);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
