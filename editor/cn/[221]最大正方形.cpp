//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：matrix = [["0","1"],["1","0"]]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：matrix = [["0"]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] 为 '0' 或 '1' 
// 
// Related Topics 数组 动态规划 矩阵 
// 👍 1019 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //
        // 单调栈
        //
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }

        int n = matrix[0].size();

        // 求得宽度
        vector<vector<int>> width(m, vector<int>(n));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '1') {
                    if (j == 0) {
                        width[i][j] = 1;
                    } else {

                        width[i][j] = width[i][j-1] + 1;
                    }
                }
            }
        }

        // 获取width之后; matrix就没啥大用了

        int ans = 0;

        // 针对每一列都有高度
        for (int j=0; j<n; j++) {
            vector<int> up(m), down(m, m);
            stack<int> monoStack;

            for (int i=0; i<m; i++) {
                while (!monoStack.empty() && width[i][j] < width[monoStack.top()][j]) {
                    // 下边第一小于的索引
                    down[monoStack.top()] = i;

                    monoStack.pop();
                }

                up[i] = monoStack.empty() ? -1 : monoStack.top();
                monoStack.push(i);
            }


            for (int i=0; i<m; i++) {
                int height = down[i] - up[i] - 1;
                int side = min(height, width[i][j]);

                ans = max(ans, side * side);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
