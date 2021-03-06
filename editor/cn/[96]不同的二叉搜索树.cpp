//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 19 
// 
// Related Topics 树 二叉搜索树 数学 动态规划 二叉树 
// 👍 1403 👎 0

/*
dp[0] * dp[0] + dp[1] => 1*1+0
dp[1] => 1
---------------------------
dp[0] * dp[1] + dp[2] => 1*1+0
dp[2] => 1
dp[1] * dp[0] + dp[2] => 1*1+1
dp[2] => 2
---------------------------
dp[0] * dp[2] + dp[3] => 1*2+0
dp[3] => 2
dp[1] * dp[1] + dp[3] => 1*1+2
dp[3] => 3
dp[2] * dp[0] + dp[3] => 2*1+3
dp[3] => 5
---------------------------
dp[0] * dp[3] + dp[4] => 1*5+0
dp[4] => 5
dp[1] * dp[2] + dp[4] => 1*2+5
dp[4] => 7
dp[2] * dp[1] + dp[4] => 2*1+7
dp[4] => 9
dp[3] * dp[0] + dp[4] => 5*1+9
dp[4] => 14
---------------------------
dp[0] * dp[4] + dp[5] => 1*14+0
dp[5] => 14
dp[1] * dp[3] + dp[5] => 1*5+14
dp[5] => 19
dp[2] * dp[2] + dp[5] => 2*2+19
dp[5] => 23
dp[3] * dp[1] + dp[5] => 5*1+23
dp[5] => 28
dp[4] * dp[0] + dp[5] => 14*1+28
dp[5] => 42
---------------------------

*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
        // 1. dp[i] : 1 到 i 为节点组成的二叉搜索树的个数为dp[i]
        // 2. 状态转移方程式
        //
        //   dp[3] = dp[2] * dp[0] + dp[1]*dp[1] + dp[0] * dp[2]
        //   这里 dp[0] = 1
        //   由此可以获取状态转移方程式：
        // dp[i] += dp[j-1] * dp[j-i]



        // dp table
        vector<int> dp(n+1, 0);

        // base case
        dp[0] = 1;


        // 从第一个节点到最后一个节点， 依次作为头节点，
        // 求每个头节点拥有的个数：dp[j-1] * dp[j-i]
        // 然后将结果依次相加
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
