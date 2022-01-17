//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
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
// Related Topics 数组 回溯 
// 👍 1148 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> ans;
    // n是棋盘大小
    // row表示当前递归到棋盘的第几行
    void backtracking(int n, int row, vector<string> &chessboard) {
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
        for (int i=0; i<row; i++) {

        }

        // 2. 检查 45角度
        

        // 3. 检查135角度
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // 思路：
        //
        //

        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
