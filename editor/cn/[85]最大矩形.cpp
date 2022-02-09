//给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
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
//输入：matrix = [["0"]]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：matrix = [["1"]]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：matrix = [["0","0"]]
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
// 1 <= row, cols <= 200 
// matrix[i][j] 为 '0' 或 '1' 
// 
// Related Topics 栈 数组 动态规划 矩阵 单调栈 
// 👍 1138 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
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
                    // 这里为啥是0
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
