//给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1： 
//
// 
//输入：k = 2, prices = [2,4,1]
//输出：2
//解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。 
//
// 示例 2： 
//
// 
//输入：k = 2, prices = [3,2,6,5,0,3]
//输出：7
//解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 
//。 
//
// 
//
// 提示： 
//
// 
// 0 <= k <= 100 
// 0 <= prices.length <= 1000 
// 0 <= prices[i] <= 1000 
// 
// Related Topics 数组 动态规划 
// 👍 641 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // k笔交易
    // 照猫画虎
    int maxProfit(int k, vector<int>& prices) {
        // 思路
        // 总共的状态有 2k + 1 种
        // 例如： k = 3
        // 0 : 未操作
        // 1 : 第1次买入
        // 2 : 第1次卖出
        // 3 : 第2次买入
        // 4 : 第2次卖出
        // 5 : 第3次买入
        // 6 : 第3次卖出
        // dp[i][j] => 第i天，状态j的持有最大钱数
        int size = prices.size();
        if (size == 0)
            return 0;
        if (k == 0)
            return 0;

        vector<vector<int>> dp(size, vector<int>(2*k+1, 0));

        for (int j=0; j<2*k+1; j++) {
            if (j % 2 == 0) {
                dp[0][j] = 0;
            } else {
                dp[0][j] -= prices[0];
            }
        }

        for (int i=1; i<size; i++) {
            for (int j=0; j<2*k+1; j++) {
                // 没有操作
                if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                // 买入状态
                } else if (j % 2 == 1) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
                // 卖出状态
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
                }
            }
        }

        return dp[size -1][2*k];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
