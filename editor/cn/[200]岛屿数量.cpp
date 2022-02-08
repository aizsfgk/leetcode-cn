//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 
// 👍 1454 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // 原始棋盘, 行, 列
    void dfs(vector<vector<char>>& grid, int row, int col) {
        // 修改
        int m = grid.size();
        int n = grid[0].size();

        // 深度优先搜索
        // 能到达的都标记为0
        grid[row][col] = '0';

        // 四个方向
        if (row-1 >= 0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
        if (row+1 <= m-1 && grid[row+1][col] == '1') dfs(grid, row+1, col);
        if (col-1 >= 0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
        if (col+1 <= n-1 && grid[row][col+1] == '1') dfs(grid, row, col+1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        //
        // 深度优先搜索
        //
        int m = grid.size(); // 行

        if (!m) {
            return 0;
        }

        int n = grid[0].size();

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
