//二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。 
//
// 请返回 封闭岛屿 的数目。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,
//0,1],[1,1,1,1,1,1,1,0]]
//输出：2
//解释：
//灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。 
//
// 示例 2： 
//
// 
//
// 
//输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：grid = [[1,1,1,1,1,1,1],
//             [1,0,0,0,0,0,1],
//             [1,0,1,1,1,0,1],
//             [1,0,1,0,1,0,1],
//             [1,0,1,1,1,0,1],
//             [1,0,0,0,0,0,1],
//             [1,1,1,1,1,1,1]]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length, grid[0].length <= 100 
// 0 <= grid[i][j] <=1 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 
// 👍 113 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int n;
    int m;

    void dfs(vector<vector<int>> &grid, int row, int col) {

        grid[row][col] = 1;

        if (row + 1 <= m-1 && grid[row+1][col] == 0) dfs(grid, row+1, col);
        if (row - 1 >= 0 && grid[row-1][col] == 0) dfs(grid, row-1, col);
        if (col + 1 <= n-1 && grid[row][col+1] == 0) dfs(grid, row, col+1);
        if (col - 1 >= 0 && grid[row][col-1] == 0) dfs(grid, row, col-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // 先把边染成水
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if ((i == 0 || i == (m -1 ) || j == 0 || j == (n - 1) ) && grid[i][j] == 0) { // 边
                    dfs(grid, i, j);
                }
            }
        }


        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) {
                    ans ++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
