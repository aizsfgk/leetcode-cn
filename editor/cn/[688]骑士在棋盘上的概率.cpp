//在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column) 开始，并尝试进行 k 次移动。行和列是 从 0 开始 的，所以左上单元格
//是 (0,0) ，右下单元格是 (n - 1, n - 1) 。 
//
// 象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。 
//
// 
//
// 每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。 
//
// 骑士继续移动，直到它走了 k 步或离开了棋盘。 
//
// 返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。 
//
// 
//
// 示例 1： 
//
// 
//输入: n = 3, k = 2, row = 0, column = 0
//输出: 0.0625
//解释: 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
//在每一个位置上，也有两种移动可以让骑士留在棋盘上。
//骑士留在棋盘上的总概率是0.0625。
// 
//
// 示例 2： 
//
// 
//输入: n = 1, k = 0, row = 0, column = 0
//输出: 1.00000
// 
//
// 
//
// 提示: 
//
// 
// 1 <= n <= 25 
// 0 <= k <= 100 
// 0 <= row, column <= n 
// 
// Related Topics 动态规划 
// 👍 171 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int dirs[8][2] = {
        {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
    };

public:
    /*

        一个骑士有 8 种可能的走法，骑士会从中以等概率随机选择一种。部分走法可能会让骑士离开棋盘，另外的走法则会让骑士移动到棋盘的其他位置，并且剩余的移动次数会减少1。

        dp[skep][i][j]:

        1. i, j不在棋盘上；dp[skep][i][j] = 0;
        2. skep = 0, dp[skep][i][j] = 1
        3. 其他情况：dp[step][i][j]= 1/8 * dp[step−1][i+di][j+dj] * di<->dj ∑

    */
    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) {
            return double(1);
        }

        // 动态规划?   // baseCase
        // 记忆化搜索? // 记忆板

        // 怎么想到动态规划的? // 记忆我是看到棋盘默认就想到了

        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n)));

        // 步数
        for (int step=0; step <= k; step++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (step == 0) { // 步子为0,肯定是1
                        dp[step][i][j] = 1;
                    } else {

                        for (auto dir : dirs) {
                            int ni = dir[0] + i;
                            int nj = dir[1] + j;
                            // 状态转移方程式 怎么来的?
                            //
                            // 有8个方向，从这8是否可以有入口呢?
                            //   1/8;
                            //
                            if (ni >= 0 && ni < n && nj >=0 && nj <n) {
                                dp[step][i][j] += dp[step-1][ni][nj] / 8; /// 到达这个位置相加
                            }
                        }
                    }
                }
            }
        }

        return dp[k][row][column];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
