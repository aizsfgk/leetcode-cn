//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
// Related Topics 数组 矩阵 模拟 
// 👍 970 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        if (matrix.empty())
            return ans;

        // 确定上下左右边界
        int u = 0; // 上
        int d = matrix.size() - 1; // 下
        int l = 0; // 左
        int r = matrix[0].size() - 1; // 右

        // 进行操作
        while (true) {
            for (int i=l; i<=r; i++) ans.push_back(matrix[u][i]); // 向右移动直到最右
            if (++u > d) break; // 重新设定上边界; 符合条件结束

            for (int i=u; i<=d; ++i) ans.push_back(matrix[i][r]); // 向下
            if (--r < l) break; // 重新设定右边界; 符合条件，结束


            for (int i=r; i>=l; --i) ans.push_back(matrix[d][i]); // 向左
            if (--d < u) break; // 重新设定下边界

            for (int i=d; i>=u; --i) ans.push_back(matrix[i][l]); // 向上
            if (++l > r) break; // 重新设定左边界
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
