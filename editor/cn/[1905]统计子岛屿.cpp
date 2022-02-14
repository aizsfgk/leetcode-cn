//给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。一个 岛屿 是由 四个方向 （水平或者竖
//直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。 
//
// 如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，那
//么我们称 grid2 中的这个岛屿为 子岛屿 。 
//
// 请你返回 grid2 中 子岛屿 的 数目 。 
//
// 
//
// 示例 1： 
//
// 输入：grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], gri
//d2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
//输出：3
//解释：如上图所示，左边为 grid1 ，右边为 grid2 。
//grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。
// 
//
// 示例 2： 
//
// 输入：grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], gri
//d2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
//输出：2 
//解释：如上图所示，左边为 grid1 ，右边为 grid2 。
//grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。
// 
//
// 
//
// 提示： 
//
// 
// m == grid1.length == grid2.length 
// n == grid1[i].length == grid2[i].length 
// 1 <= m, n <= 500 
// grid1[i][j] 和 grid2[i][j] 都要么是 0 要么是 1 。 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 
// 👍 33 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // 符合返回 1
    // 否则返回 0
    int bfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int row, int col) {
        int m = grid1.size();
        int n = grid1[0].size();

        grid2[row][col] = 0;
        int check = grid1[row][col];

        queue<pair<int,int>> que;
        que.push({row, col});
        while (!que.empty()) {
            auto ele = que.front(); que.pop();

            for (auto dir : dirs) {
                int newR = ele.first + dir[0]; // 新方法一定是新元素
                int newC = ele.second + dir[1];

                if (newR >=0 && newR <m && newC >=0 && newC <n && grid2[newR][newC] == 1) {

                    // 入队
                    que.push({newR, newC}); // 入队并置为0
                    grid2[newR][newC] = 0;  //

                    if (grid1[newR][newC] != 1) { // 不符合结果
                        check = 0;
                    }
                }
            }

        }

        return check;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // 统计子岛屿
        //
        // BFS : 宽度优先搜索

        int m = grid2.size();
        int n = grid2[0].size();

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid2[i][j] == 1) {
                    ans += bfs(grid1, grid2, i, j);
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
