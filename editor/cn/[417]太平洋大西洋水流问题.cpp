//有一个 m × n 的长方形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。 
//
// 这个岛被分割成一个个方格网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平
//面的高度 。 
//
// 岛上雨水较多，如果相邻小区的高度 小于或等于 当前小区的高度，雨水可以直接向北、南、东、西流向相邻小区。水可以从海洋附近的任何细胞流入海洋。 
//
// 返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋
// 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
//输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// 
//
// 示例 2： 
//
// 
//输入: heights = [[2,1],[1,2]]
//输出: [[0,0],[0,1],[1,0],[1,1]]
// 
//
// 
//
// 提示： 
//
// 
// m == heights.length 
// n == heights[r].length 
// 1 <= m, n <= 200 
// 0 <= heights[r][c] <= 105 
// 
// Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 
// 👍 331 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int m;
    int n;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int i, int j) {
        if (vis[i][j]) {
            return;
        }

        vis[i][j] = true;
        int x = heights[i][j];
        for (auto dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < m && nj>=0 && nj <n && !vis[ni][nj] && heights[ni][nj] >= x) {
                dfs(heights, vis, ni, nj);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 结果既可以流到大西洋，也可以流到太平洋的点
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> P(m, vector<bool>(n, false));
        vector<vector<bool>> A(m, vector<bool>(n, false));

        // 左边，上边太平洋； 右边，下边大西洋
        // 左边和右边
        for (int i=0; i<m; i++) {
            dfs(heights, P, i, 0);
            dfs(heights, A, i, n-1);
        }

        // 上边和下边
        for (int j=0; j<n; j++) {
            dfs(heights, P, 0, j);
            dfs(heights, A, m-1, j);
        }

        vector<vector<int>> ans;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (P[i][j] && A[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
