//有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。 
//
// 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i -
// 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。 
//
// 求所能获得硬币的最大数量。 
//
// 
//示例 1：
//
// 
//输入：nums = [3,1,5,8]
//输出：167
//解释：
//nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167 
//
// 示例 2： 
//
// 
//输入：nums = [1,5]
//输出：10
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// 1 <= n <= 500 
// 0 <= nums[i] <= 100 
// 
// Related Topics 数组 动态规划 
// 👍 928 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //
        //
        // 最大硬币数； 这个怎么想到动态规划的啊???
        //
        //
        /*
        思路及算法
        */
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2));



        // 开始的气球
        for (int l = 1; l<=n; l++) {
            for (int i=1; i<=n-l+1; i++) {
                int j = i + l - 1;
                for (int k=i; k<=j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1] * nums[k] * nums[j+1]);
                }
            }
        }
        return dp[1][n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)
