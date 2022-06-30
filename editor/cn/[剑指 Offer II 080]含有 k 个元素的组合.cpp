//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2: 
//
// 
//输入: n = 1, k = 1
//输出: [[1]] 
//
// 
//
// 提示: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// 
//
// 注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/ 
// Related Topics 数组 回溯 👍 23 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int idx, int n, int k) {
        if (k == 0) {
            ans.push_back(path);
            return;
        }

        for (int i=idx; i<=n; i++) {
            path.push_back(i);
            backtracking(i+1, n, k-1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(1, n, k);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
