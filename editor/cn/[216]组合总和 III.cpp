//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。 
//
// 说明： 
//
// 
// 所有数字都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: k = 3, n = 7
//输出: [[1,2,4]]
// 
//
// 示例 2: 
//
// 输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
// 
// Related Topics 数组 回溯 
// 👍 412 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int n, int k, int startIdx, int target) {

        // 减枝操作
        if (target < 0) {
            return;
        }

        // 中止条件
        if (k == path.size() && target == 0) {
            ans.push_back(path);
            return;
        }

        // 遍历逻辑
        for (int i=startIdx; i<=n; i++) {
            path.push_back(i);
            backtracking(n, k, i+1, target-i); // 因为可选择列表中没有重复元素
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(9, k, 1, n);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
