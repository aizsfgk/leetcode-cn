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
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0 ) return false;

        int target = sum / 2;

        // dp[i] 重量为i的背包，最多可以收纳的容量是dp[i]
        // 01背包
        vector<int> dp(20001, 0);
        for (int i=0; i<nums.size(); i++) { // 遍历物品
            for (int j=target; j>=nums[i]; j--) { // 遍历背包重量; 从后向前遍历，防止重复选择
                // i 位置的物品 重量是nums[i], 价值也是nums[i];
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]); /// 最大的一个价值
            }
        }

        /// dp[i]的数值一定是小于等于i的。
        /// 如果dp[i] == i 说明，集合中的子集总和正好可以凑成总和i，理解这一点很重要。
        // target 重量的 价值 也是 target;
        // 说明可以选出物品组成 target 数
        if (dp[target] == target) return true;

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
