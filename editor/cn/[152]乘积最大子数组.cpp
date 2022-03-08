//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 
//
// 
//
// 示例 1: 
//
// 输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
// 
//
// 示例 2: 
//
// 输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。 
// Related Topics 数组 动态规划 
// 👍 1478 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
    动态转移方程：
    maxDP[i + 1] = max(maxDP[i] * A[i + 1], A[i + 1],minDP[i] * A[i + 1])
    minDP[i + 1] = min(minDP[i] * A[i + 1], A[i + 1],maxDP[i] * A[i + 1])
    dp[i + 1] = max(dp[i], maxDP[i + 1])


    */
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int maxAns = INT_MIN, imax = 1, imin = 1;
        //
        // [2,3,-2,4]
        //
        for (int i=0; i<n; i++) {
            // 对动态规划的总结
            // 当前值小于0； 最大值会变为最小值，最小值会变为最大值
            if (nums[i] < 0) {
                swap(imax, imin);
            }

            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);

            maxAns = max(maxAns, imax);
        }



        return maxAns;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
