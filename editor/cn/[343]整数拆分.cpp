//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
//
// 示例 1: 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。 
// Related Topics 数学 动态规划 
// 👍 664 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        // 整数拆分

        // 1. 确定 dp[i]的含义
        // dp[i] => 分拆数字i可以得到的最大乘积为dp[i]
        //
        // 2. 状态转移方程式
        //  dp[i] = max(dp[i],  max( (i-j)*j, dp[i-j]*j) );
        //
        // 3. 初始化
        // dp[2] = 1;
        // dp[1] = 1;
        // dp[0] = 0;
        //
        // 4. 确定遍历顺序
        //  从前向后遍历
        //
        vector<int> dp(n+1);
        dp[2] = 1;
        for (int i=3; i<=n; i++) {
            // 为何是 j<i-1; 通过base case 推到出来的
            // 因为; i-j >= 2 ==> j< i-1
            for (int j=1; j<i-1; j++) {
                dp[i] = max( dp[i], max( (i-j)*j, dp[i-j]*j ) );
            }
        }

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
