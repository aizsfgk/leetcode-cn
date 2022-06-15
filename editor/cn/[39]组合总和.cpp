//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的
// 所有不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。 
//
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
//
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。 
//
// 
//
// 示例 1： 
//
// 
//输入：candidates = [2,3,6,7], target = 7
//输出：[[2,2,3],[7]]
//解释：
//2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
//7 也是一个候选， 7 = 7 。
//仅有这两种组合。 
//
// 示例 2： 
//
// 
//输入: candidates = [2,3,5], target = 8
//输出: [[2,2,2,2],[2,3,3],[3,5]] 
//
// 示例 3： 
//
// 
//输入: candidates = [2], target = 1
//输出: []
// 
//
// 示例 4： 
//
// 
//输入: candidates = [1], target = 1
//输出: [[1]]
// 
//
// 示例 5： 
//
// 
//输入: candidates = [1], target = 2
//输出: [[1,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都 互不相同 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯 
// 👍 1702 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    /*
    四个问题：
    1. 可选元素中是否包含重复元素(如果重复，可能需要同层去重)
    2. 是否可以重复地使用同一个元素
    3. 结果path中是否可以含有不同的元素
    4. 结果ans中，是否不能含有重复的元素(layerUse 去重)

    */
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int idx) {
        if (target < 0)
            return;

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i=idx; i<candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i); // i 是相同的，所有是重复元素
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtracking(candidates, target, 0);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
