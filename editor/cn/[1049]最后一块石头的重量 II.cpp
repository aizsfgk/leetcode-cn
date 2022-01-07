//有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。 
//
// 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下： 
//
// 
// 如果 x == y，那么两块石头都会被完全粉碎； 
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。 
// 
//
// 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。 
//
// 
//
// 示例 1： 
//
// 
//输入：stones = [2,7,4,1,8,1]
//输出：1
//解释：
//组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
//组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
//组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
//组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
// 
//
// 示例 2： 
//
// 
//输入：stones = [31,26,33,21,40]
//输出：5
// 
//
// 示例 3： 
//
// 
//输入：stones = [1,2]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= stones.length <= 30 
// 1 <= stones[i] <= 100 
// 
// Related Topics 数组 动态规划 
// 👍 372 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 思路：
        //   通读题目，本质就是要将石头分成2堆，让这两堆差额最少，是一个最值问题?
        // 考虑如何可以让两个堆差值最小呢? 让每个堆都无限接近 sum/2 , 则其差值最小。
        // 转换成 01背包最值问题：将一堆 stones 的石头，放进容量是 sum/2 的背包，求放进
        // 石头的最大重量maxWeight, 则结果是 sum - 2 * maxWeight。
        //
        // 01背包问题
        //
        // dp[j] : 容量为j的背包，最多可以背dp[j]这么重的石头。
        //
        //

        int sum = accumulate(stones.begin(), stones.end(), 0);

        // 100 * 30 / 2 +1 == 15001
        vector<int> dp(15001, 0);

        int target = sum/2;

        for (int i=0; i<stones.size(); i++) { // 遍历物品; 这里是石头。
            for (int j = target; j>=stones[i]; j--) { // 遍历背包; 不同容量的背包
                // 为何可以使用一维数组???
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }

        return sum - 2*dp[target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
