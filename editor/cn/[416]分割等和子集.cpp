//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
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
// Related Topics 数组 动态规划 
// 👍 1074 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 子集划分
        // 是否可以出现 总和为 sum/2 的子集
        //
        //
        //
        //
        // 题目总和不会大于20000, 背包最大只需要其中一半，因此10001足够了
        // dp[i]表示 背包总容量是i，最⼤可以凑成i的⼦集总和为dp[i]。
        vector<int> dp(10001, 0);

        int sum = 0;

        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }

        // 和不是偶数
        if (sum % 2 == 1) return false;

        int target = sum / 2;

        // 01 背包
        for (int i=0; i<nums.size(); i++) {
            for (int j=target; j>=nums[i]; j--) { // 每个元素一定是不可重复放入，从大到小
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
            }
        }

        if (dp[target] == target) return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
