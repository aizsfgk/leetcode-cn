//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
//。
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X"
//,"X"]]
//输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都
//会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
// 
//
// 示例 2： 
//
// 
//输入：board = [["X"]]
//输出：[["X"]]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 200 
// board[i][j] 为 'X' 或 'O' 
// 
// 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 
// 👍 727 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};
    int m;
    int n;
    void dfs(vector<vector<char>> &board, int row, int col) {
        // 不是O 直接返回
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') {
            return;
        }

        board[row][col] = 'A';
        for (auto dir : dirs) {
            int newX = row + dir[0];
            int newY = col + dir[1];
            dfs(board, newX, newY);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // 深度优先遍历：
        m = board.size();
        n = board[0].size();

        for (int i=0; i<m; i++) {
            dfs(board, i, 0);   // 每一列
            dfs(board, i, n-1);
        }

        for (int j=0; j<n; j++) {
            dfs(board, 0, j);  // 每一行
            dfs(board, m-1, j);
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] = 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
