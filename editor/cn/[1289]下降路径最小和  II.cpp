//给你一个 n x n 整数矩阵 arr ，请你返回 非零偏移下降路径 数字和的最小值。 
//
// 非零偏移下降路径 定义为：从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
//输出：13
//解释：
//所有非零偏移下降路径包括：
//[1,5,9], [1,5,7], [1,6,7], [1,6,8],
//[2,4,8], [2,4,9], [2,6,7], [2,6,8],
//[3,4,8], [3,4,9], [3,5,7], [3,5,9]
//下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[7]]
//输出：7
// 
//
// 
//
// 提示： 
//
// 
// n == grid.length == grid[i].length 
// 1 <= n <= 200 
// -99 <= grid[i][j] <= 99 
// 
// Related Topics 数组 动态规划 矩阵 
// 👍 62 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // 首行元素
        int i1 = -1, i2 = -1;
        for (int j=0; j<n; j++) {
             int val = grid[0][j];
             dp[0][j] = val;

             if (val < (i1 == -1 ? INT_MAX : grid[0][i1])) {
                i2 = i1;
                i1 = j;
             } else if (val < (i2 == -1 ? INT_MAX : grid[0][i2])) {
                i2 = j;
             }
        }

        for (int i=1; i<n; i++) {
            int ti1 = -1, ti2 = -1;

            for (int j=0; j<n; j++) {

//                dp[i][j] = INT_MAX;
                int val = grid[i][j]; // 拿到这个值

                if (j != i1) {
                    dp[i][j] = dp[i-1][i1] + val;
                } else {
                    dp[i][j] = dp[i-1][i2] + val;
                }

                // 更新ti1, ti2

                if (dp[i][j] < ( ti1 == -1 ? INT_MAX : dp[i][ti1])) {
                    ti2 = ti1;
                    ti1 = j;
                } else if ( dp[i][j] < (ti2 == -1 ? INT_MAX : dp[i][ti2])) {
                    ti2 = j;
                }
            }

            i1 = ti1;
            i2 = ti2;
        }

        int ans = INT_MAX;
        for (int j=0; j<n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
