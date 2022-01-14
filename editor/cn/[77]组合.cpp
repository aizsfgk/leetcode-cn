//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
// Related Topics 数组 回溯 
// 👍 821 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans; // 结果集合
    vector<int> path; // 路径

    void backtracking(int n, int k, int idx) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        for (int i=idx; i<=n; i++) {
            path.push_back(i);  // 处理节点
            backtracking(n, k, i+1); // 递归
            path.pop_back(); // 回溯
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        // 思路
        // 回溯三部曲
        // 1. 递归函数的返回值和参数
        // 2. 回溯的中止条件
        // 3. 单层搜索的结果

        backtracking(n, k, 1);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
