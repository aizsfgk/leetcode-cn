//给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。 
//
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。 
//
// 
//
// 
//
// 示例 1: 
//
// 
//输入: rowIndex = 3
//输出: [1,3,3,1]
// 
//
// 示例 2: 
//
// 
//输入: rowIndex = 0
//输出: [1]
// 
//
// 示例 3: 
//
// 
//输入: rowIndex = 1
//输出: [1,1]
// 
//
// 
//
// 提示: 
//
// 
// 0 <= rowIndex <= 33 
// 
//
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？ 
// Related Topics 数组 动态规划 
// 👍 353 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 必须是合法的行数; 以0行开始
        vector<vector<int>> ans(rowIndex+1);

        for (int i=0; i<=rowIndex; i++) {
            ans[i].resize(i+1);

            ans[i][0] = ans[i][i] = 1;
            for (int j=1; j<i; j++) {
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }

        return ans[rowIndex];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
