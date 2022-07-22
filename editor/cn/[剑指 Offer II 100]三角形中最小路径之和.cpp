//给定一个三角形 triangle ，找出自顶向下的最小路径和。 
//
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果
//正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//输出：11
//解释：如下面简图所示：
//   2
//  3 4
// 6 5 7
//4 1 8 3
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
// 
//
// 示例 2： 
//
// 
//输入：triangle = [[-10]]
//输出：-10
// 
//
// 
//
// 提示： 
//
// 
// 1 <= triangle.length <= 200 
// triangle[0].length == 1 
// triangle[i].length == triangle[i - 1].length + 1 
// -10⁴ <= triangle[i][j] <= 10⁴ 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？ 
// 
//
// 
//
// 注意：本题与主站 120 题相同： https://leetcode-cn.com/problems/triangle/ 
// Related Topics 数组 动态规划 👍 17 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];

        for (int i=1; i<n; i++) {
            // 0索引只能取上一行的0索引位置
            dp[i][0] = dp[i-1][0] + triangle[i][0];

            for (int j=1; j<i; j++) {
                // 取上一行当前j或者上一行当前j-1位置
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }

            // 最后位置，只能取上一行前一个位置
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }

        // 取最后一行，最小的元素值
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)
