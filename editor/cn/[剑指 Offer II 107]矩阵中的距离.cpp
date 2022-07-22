//给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。 
//
// 两个相邻元素间的距离为 1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
//输出：[[0,0,0],[0,1,0],[0,0,0]]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
//输出：[[0,0,0],[0,1,0],[1,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= m, n <= 10⁴ 
// 1 <= m * n <= 10⁴ 
// mat[i][j] is either 0 or 1. 
// mat 中至少有一个 0 
// 
//
// 
//
// 注意：本题与主站 542 题相同：https://leetcode-cn.com/problems/01-matrix/ 
// Related Topics 广度优先搜索 数组 动态规划 矩阵 👍 28 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // 最近0格子的距离

        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));

        queue<pair<int, int>> q;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >=0 && ni < m && nj>=0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

        return dist;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
