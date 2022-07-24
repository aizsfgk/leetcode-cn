//给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。 
//
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
//输出：4 
//解释：最长递增路径为 [1, 2, 6, 9]。 
//
// 示例 2： 
//
// 
//
// 
//输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
//输出：4 
//解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
// 
//
// 示例 3： 
//
// 
//输入：matrix = [[1]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// 0 <= matrix[i][j] <= 2³¹ - 1 
// 
//
// 
//
// 注意：本题与主站 329 题相同： https://leetcode-cn.com/problems/longest-increasing-path-
//in-a-matrix/ 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 记忆化搜索 数组 动态规划 矩阵 👍 23 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& lengths, int i, int j)
    {
        if (lengths[i][j] != 0)
        {
            return lengths[i][j];   //当前节点已计算过，直接返回其值，避免重复计算
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int length = 1;             //长度初始为1，即当前一个节点

        for (pair<int, int> dir : dirs)
        {
            int x = i + dir.first;
            int y = j + dir.second;

            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j])
            {
                // +1 表示包含当前点的长度
                length = max(length, dfs(matrix, lengths, x, y) + 1);
            }
        }

        lengths[i][j] = length;     //记录该点的最长路径
        return length;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> lengths(matrix.size(), vector<int>(matrix[0].size()));

        int longest = 0;
        for (int i = 0; i < matrix.size(); ++ i)
        {
            for (int j = 0; j < matrix[0].size(); ++ j)
            {
                longest = max(longest, dfs(matrix, lengths, i, j));
            }
        }

        return longest;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
