//给你一个整数数组 nums 和一个整数 target 。 
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ： 
//
// 
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。 
// 
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], target = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 20 
// 0 <= nums[i] <= 1000 
// 0 <= sum(nums[i]) <= 1000 
// -1000 <= target <= 1000 
// 
// Related Topics 数组 动态规划 回溯 
// 👍 991 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
    int findTargetSumWays(vector<int>& nums, int target) {
        // 01背包排列组合问题
        // 思路：
        //   dp[j] => 填满j容量的包，有dp[j]种方法
        //
        //

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 目标大于总和，当然没有方案
        if (target > sum)
            return 0;

        // 为何没有方案?
        //
        if ((target+sum) % 2 == 1) {
            return 0;
        }

        // 背包容量
        int bagSize = (target+sum) / 2;
        // dp table
        vector<int> dp(bagSize+1, 0); // 容量为j的包，有dp[j]种方法

        // 初始值
        dp[0] = 1;

        // 遍历模板
        for (int i=0; i<nums.size(); i++) {
            for (int j=target; j>=nums[i]; j--) {
                // 状态转移方程式
                dp[j] += dp[j - nums[i]];
            }
        }

        // 返回结果
        return dp[bagSize];
    }
    */

    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            https://leetcode-cn.com/problems/target-sum/solution/dai-ma-sui-xiang-lu-494-mu-biao-he-01bei-rte9/
        */

        int S = target;

        // 1. 求总和
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];


        if (abs(S) > sum) return 0; // 此时没有方案

        if ((S + sum) % 2 == 1) return 0; // 此时没有方案


        int bagSize = (S + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
