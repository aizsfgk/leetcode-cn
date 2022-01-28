//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 矩阵 模拟 
// 👍 583 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        if (n == 0)
            return ans;

        int l = 0;
        int r = n-1;
        int u = 0;
        int d = n-1;

        // 基本逻辑
        int num = 0;
        while (true) {
            for (int i=l; i<=r; ++i)
                ans[u][i] = ++num;
            if (++u > d) break;

            for (int i=u; i<=d; ++i)
                ans[i][r] = ++num;
            if (--r < l) break;

            for (int i=r; i>=l; --i)
                ans[d][i] = ++num;
            if (--d < u) break;

            for (int i=d; i>=u; --i)
                ans[i][l] = ++num;
            if (++l > r) break;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
