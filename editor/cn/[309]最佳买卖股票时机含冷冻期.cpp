//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 示例: 
//
// 输入: [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
// Related Topics 数组 动态规划 
// 👍 1020 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    int maxProfit(vector<int>& prices) {
    /*
        // 加上了冷冻期
        // 思路：
        //   四个状态：
        //   0 ： 持有股票（之前买了，或者今天买了）
        //   1 :  两天前就卖出了股票，渡过了冷静期，今天保持卖出股票状态
        //   2 :  卖出股票状态
        //   3 :  今天为冷冻期状态，冷冻期状态只有一天
        // dp[i][j] => 第i天在j状态获得的最大钱数

        int size = prices.size();
        if (size == 0)
            return 0;

        vector<vector<int>> dp(size, vector<int>(4, 0));
        dp[0][0] -= prices[0];

        for (int i=1; i<size; i++) {

            // 1. 前一天持有股票： dp[i][0] = dp[i-1][0]
            // 2. 今天买入了股票：
            //      a. 前一是冷冻期：dp[i][0] = dp[i-1][3] - prices[i]
            //      b. 前一天保持卖出股票状态：dp[i][0] = dp[i-1][1] - prices[i]
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][3], dp[i-1][1]) - prices[i]);

            // 1. 前一天是状态2: dp[i][1] = dp[i-1][1]
            // 2. 前一天是冷静期: dp[i][1] = dp[i-1][3]
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);

            // 1. 昨天一定是买入股票状态：dp[i][2] = dp[i-1][0] + prices[i]
            dp[i][2] = dp[i-1][0] + prices[i];

            // 1. 昨天卖出了股票 dp[i][3] = dp[i-1][2]
            dp[i][3] = dp[i-1][2];
        }

        // 取不持有股票的最大值
        return max(dp[size-1][3], max(dp[size-1][1], dp[size-1][2]));

    */

        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if (n == 0) {
                return 0;
            }

            vector<vector<int>> dp(n, vector<int>(3, 0));

            dp[0][0] -= prices[0];

            for (int i=1; i<n; i++) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
                dp[i][1] = dp[i-1][0] + prices[i];
                dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
            }

            return max(dp[n-1][1], dp[n-1][2]);
        }
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
