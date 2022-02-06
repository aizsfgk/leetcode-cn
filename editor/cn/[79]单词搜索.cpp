//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SE
//E"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
// Related Topics 数组 回溯 矩阵 
// 👍 1171 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {
private:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 右，左， 上，下
    int n;
    int m;

    bool ans = false;
    string curWord;
    vector<vector<int>> visited;
public:
    void backtracking(vector<vector<char>> &board, int x, int y, string curStr) {
        if (x < 0 || x >=n || y<0 || y>=m || visited[x][y] || curStr.size() >= curWord.size()) {
            return;
        }

        visited[x][y] = 1;
        curStr.push_back(board[x][y]);

        if (curStr.size() == curWord.size() && curStr == curWord) {
            ans = true;
            return;
        }

        for (auto dir : dirs) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            backtracking(board, newX, newY, curStr);
        }

        curStr.pop_back();
        visited[x][y] = 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        visited = vector<vector<int>>(n, vector<int>(m, 0));
        curWord = word;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                backtracking(board, i, j, "");
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        // 首字母不同直接返回false
        if (board[i][j] != s[k]) {
            return false;
        // 相同且是结尾字母，则返回true
        } else if (k == s.length() - 1) {
            return true;
        }


        visited[i][j] = true;
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            // 合法边界
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                // 没有访问过，才去访问
                if (!visited[newi][newj]) {
                    // 有一个为真
                    result = result || check(board, visited, newi, newj, s, k + 1);
                }
            }
        }
        visited[i][j] = false;

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
