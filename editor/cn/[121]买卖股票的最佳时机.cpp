//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。 
//
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。 
//
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 
//
// 示例 2： 
//
// 
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 105 
// 0 <= prices[i] <= 104 
// 
// Related Topics 数组 动态规划 
// 👍 2041 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 最大利润
/*
        // 思路：
        //   1. 贪心：因为股票只买卖一次
        //           取左边最小值；取右边最大值；相减得出的值就是最大收益.
        int low = INT_MAX;
        int ans = 0;

        for (int i=0; i<prices.size(); i++) {
            low = min(low, prices[i]);

            ans = max(ans, prices[i] - low);
        }

        return ans;
*/
        // 思路：
        //  动态规划
        // dp[i][0] : 第i天持有股票所得的最多现金
        // dp[i][1] : 第i天不持有股票所得的最多现金
        //
        // 状态转移方程式:
        //
        // 第i-1天就持有股票，那么就保持现状，所得现⾦就是昨天持有股票的所得现⾦ 即：dp[i - 1][0]
        // 第i天买⼊股票，所得现⾦就是买⼊今天的股票后所得现⾦即：-prices[i]
        //
        // 第i-1天就不持有股票，那么就保持现状，所得现⾦就是昨天不持有股票的所得现⾦ 即：dp[i - 1][1]
        // 第i天卖出股票，所得现⾦就是按照今天股票佳价格卖出后所得现⾦即：prices[i] + dp[i - 1][0]
        //
        //
        //
        int size = prices.size();

        if (size == 0)
            return 0;

        // dp table
        vector<vector<int>> dp(size, vector<int>(2));

        dp[0][0] -= prices[0];
        dp[0][1] = 0;

        for (int i=1; i<size; i++) {
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
        }

        return dp[size-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
