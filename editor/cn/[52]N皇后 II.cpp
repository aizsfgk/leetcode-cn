//n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 4
//输出：2
//解释：如上图所示，4 皇后问题存在两个不同的解法。
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
// 1 <= n <= 9 
// 
// 
// 
// Related Topics 回溯 
// 👍 334 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> ans;

    // n是棋盘大小
    // row表示当前递归到棋盘的第几行

    // 从第0行开始(第一行)
    void backtracking(int n, int row, vector<string> &chessboard) {

        // 行数到达则放入
        // chessboard 相当于path
        if (row == n) {
            ans.push_back(chessboard);
            return;
        }

        for (int col = 0; col<n; col++) {
            if (isValid(row, col, chessboard, n)) { // 验证合法性
                chessboard[row][col] = 'Q';
                backtracking(n, row+1, chessboard);
                chessboard[row][col] = '.'; // 回溯，撤销皇后
            }
        }
    }

    bool isValid(int row, int col, vector<string> &chessboard, int n) {
        // 1. 检查列
        for (int i=0; i<row; i++) { // 这是一个剪枝
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        // 2. 检查 45角度
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--,j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        // 3. 检查135角度
        for (int i=row-1,j=col+1; i>=0 && j<n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
public:
    int totalNQueens(int n) {
         // 初始化一个棋盘
        vector<string> chessboard(n, string(n, '.'));
        // 然后进行回溯递归
        backtracking(n, 0, chessboard);

        return ans.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
