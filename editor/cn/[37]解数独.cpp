//编写一个程序，通过填充空格来解决数独问题。 
//
// 数独的解法需 遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） 
// 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 
//
// 
// 
// 
// 示例： 
//
// 
//输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5","."
//,".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".","."
//,"3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"
//],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],["
//.",".",".",".","8",".",".","7","9"]]
//输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"
//],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["
//4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","
//6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","
//5","2","8","6","1","7","9"]]
//解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
//
//
// 
//
// 
//
// 提示： 
//
// 
// board.length == 9 
// board[i].length == 9 
// board[i][j] 是一位数字或者 '.' 
// 题目数据 保证 输入数独仅有一个解 
// 
// 
// 
// 
// Related Topics 数组 回溯 矩阵 
// 👍 1085 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) { // 遍历⾏
            for (int j = 0; j < board[0].size(); j++) { // 遍历列
                if (board[i][j] != '.') continue;

                for (char k = '1'; k <= '9'; k++) { // (i, j) 这个位置放k是否合适
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k; // 放置k
                        if (backtracking(board)) return true; // 如果找到合适⼀组⽴刻返回
                        board[i][j] = '.'; // 回溯，撤销k
                    }
                }

                return false; // 9个数都试完了，都不⾏，那么就返回false
            }
        }
        return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
    }

    // 判断合法性
    bool isValid(int row, int col,  char val, vector<vector<char>> &board) {
        // 行是否重复
        for (int i=0; i<9; i++) {
            if (board[row][i] == val) {
                return false;
            }
        }

        // 列是否重复
        for (int j=0; j<9; j++) {
            if(board[j][col] == val) {
                return false;
            }
        }

        // 9个小格，判断
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3; // 这里必须是col

        for (int i=startRow; i<startRow+3; i++) {
            for (int j=startCol; j<startCol+3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 思路：二维问题
        // 1. bool 返回值
        // 2. 不需要中止条件，棋盘填满就行
        // 3. ⼀个for循环遍历棋盘的⾏，⼀个for循环遍历棋盘的列，⼀⾏⼀列确定下来之后，递归遍历这个位置放9
        //      个数字的可能性！
        backtracking(board);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
