//给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。 
//
// 注意：此题 matrix 输入格式为一维 01 字符串数组。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：matrix = ["10100","10111","11111","10010"]
//输出：6
//解释：最大矩形如上图所示。
// 
//
// 示例 2： 
//
// 
//输入：matrix = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：matrix = ["0"]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：matrix = ["1"]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：matrix = ["00"]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// rows == matrix.length 
// cols == matrix[0].length 
// 0 <= row, cols <= 200 
// matrix[i][j] 为 '0' 或 '1' 
// 
//
// 
//
// 注意：本题与主站 85 题相同（输入参数格式不同）： https://leetcode-cn.com/problems/maximal-
//rectangle/ 
// Related Topics 栈 数组 动态规划 矩阵 单调栈 👍 48 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        /*
        1. 每行开始，确定一个柱状图，那么有几行，就有几个柱状图；
        2. 然后使用84的方法求柱状图的最大面积；进而求出最终的最大面积
           值得注意的是：这里是宽高颠倒了；宽代表之前的高；高代表之前的宽

            类似这种感觉     up
            | ---- width ----- |
            ---
            -
            ----
            --
            -----------
            ------
                            down

        */
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }

        int n = matrix[0].size();

        vector<vector<int>> width(m, vector<int>(n, 0));

        // 求出每一列的最大宽度
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '1') { // 如果是 1 才有效
                    // 0索引 则只能为1；否则等于前一个+1;
                    width[i][j] = (j == 0 ? 0 : width[i][j-1]) + 1;
                }
            }
        }

        // 开始使用单调栈
        int ans = 0;

        // 针对每一列，都有高度
        for (int j=0; j<n; j++) {
            // up 被认为是低位； down 表示高位
            vector<int> up(m), down(m, m);

            stack<int> monoStack;

            for (int i=0; i<m; i++) {
                while (!monoStack.empty() && width[i][j] < width[monoStack.top()][j]) {
                    down[monoStack.top()] = i;
                    monoStack.pop();
                }

                up[i] = monoStack.empty() ? -1 : monoStack.top();
                monoStack.push(i);
            }

            // 遍历没一行；求出最大高度
            for (int i=0; i<m; i++) {
                int curHeight = down[i]-up[i] - 1;
                ans = max(ans, curHeight * width[i][j]);
            }
        }

        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
