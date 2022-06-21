//给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。 
//
// 单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使
//用。 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f",
//"l","v"]], words = ["oath","pea","eat","rain"]
//输出：["eat","oath"]
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], words = ["abcb"]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 12 
// board[i][j] 是一个小写英文字母 
// 1 <= words.length <= 3 * 10⁴ 
// 1 <= words[i].length <= 10 
// words[i] 由小写英文字母组成 
// words 中的所有字符串互不相同 
// 
// Related Topics 字典树 数组 字符串 回溯 矩阵 👍 672 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> ans;
    int m;
    int n;

    unordered_set<string> memo;

    int dirs[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(const vector<vector<char>> &board, vector<vector<bool>> &visited, string curStr, int i, int j) {
        curStr.push_back(board[i][j]);

        if (curStr.size() > 10) return;

        if (memo.find(curStr) != memo.end()) {
            ans.push_back(curStr);
            memo.erase(curStr);
        }

        for (auto dir : dirs) {
            int newX = dir[0] + i;
            int newY = dir[1] + j;

            if (newX >= 0 && newY >= 0 && newX < m && newY < n && !visited[newX][newY]) {
                visited[newX][newY] = true;
                dfs(board, visited, curStr, newX, newY);
                 visited[newX][newY] = false;
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));

        for (const string &s : words) {
            memo.insert(s);
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                visited[i][j] = true;
                dfs(board, visited, "", i, j);
                visited[i][j] = false;
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
