//你现在手里有一份大小为 n x n 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋单
//元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。如果网格上只有陆地或者海洋，请返回 -1。 
//
// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - 
//x1| + |y0 - y1| 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：grid = [[1,0,1],[0,0,0],[1,0,1]]
//输出：2
//解释： 
//海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：grid = [[1,0,0],[0,0,0],[0,0,0]]
//输出：4
//解释： 
//海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
// 
//
// 
//
// 提示： 
//
// 
//
// 
// n == grid.length 
// n == grid[i].length 
// 1 <= n <= 100 
// grid[i][j] 不是 0 就是 1 
// 
// Related Topics 广度优先搜索 数组 动态规划 矩阵 
// 👍 245 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int m = grid.size();
        int n = grid[0].size();

        // 先将所有陆地入队
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                }
            }
        }

        // 从各个陆地一圈一圈的遍历海洋，最后遍历到的海洋，就是离陆地最远的海洋
        // BFS
        bool hasOcean = false;
        pair<int,int> point;
        int ans = 0;
        while (!que.empty()) {
            point = que.front(); que.pop();
            int x = point.first;
            int y = point.second;

            for (auto dir : dirs) {
                int newX = dir[0] + x;
                int newY = dir[1] + y;
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0) {
                    continue;
                }

//                ans = max(ans, grid[x][y]); // 可以这里更新最大值
                grid[newX][newY] = grid[x][y] + 1; // 直接修改grid, 无需额外空间记录是否访问; 1,2,3,4


                hasOcean = true;
                que.push({newX, newY});
            }
        }

        if (!hasOcean) {
            return -1;
        }

//        return ans;
        return grid[point.first][point.second] - 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
