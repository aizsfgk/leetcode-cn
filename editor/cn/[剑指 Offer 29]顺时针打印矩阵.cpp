//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 
//
// 
//
// 示例 1： 
//
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= matrix.length <= 100 
// 0 <= matrix[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
// Related Topics 数组 矩阵 模拟 
// 👍 415 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //
        // 顺时针打印
        //

        vector<int> ans;

        int m = matrix.size();
        if (m == 0) return ans;

        int n = matrix[0].size();


        int up = 0, down = m-1, left = 0, right = n - 1;

        while (true) {
            for (int i=left; i<=right; i++)
                ans.push_back(matrix[up][i]);
            if (++up > down) break;

            for (int i=up; i<=down; i++) {
                ans.push_back(matrix[i][right]);
            }
            if (--right < left) break;

            for (int i=right; i>=left; i--) {
                ans.push_back(matrix[down][i]);
            }
            if (--down < up) break;

            for (int i=down; i>=up; i--) {
                ans.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
