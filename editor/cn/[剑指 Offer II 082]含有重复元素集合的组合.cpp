//给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
//。 
//
// candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// 
//
// 注意：本题与主站 40 题相同： https://leetcode-cn.com/problems/combination-sum-ii/ 
// Related Topics 数组 回溯 👍 23 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(const vector<int> &candidates, vector<bool> &used, int idx, int target) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i=idx; i<candidates.size(); i++) {

            /*
            为啥和 子集2 的同层去重不一样?
            答： 考虑的点不一样；
            子集问题，只是选不选；只强调重复性
            组合问题，目的是为了组成target; 情况是 path 中可以有重复元素； 而同层分叉的时候，如果之前相同的元素没有用，本次也应该不用
            */
            if (i > 0 && candidates[i-1] == candidates[i] && !used[i-1])
                continue;


//            if (layerUsed[candidates[i]] != 0)
//                continue;

//            layerUsed[candidates[i]] == 1;
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, used, i+1, target-candidates[i]);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return ans;

        sort(candidates.begin(), candidates.end());

        vector<bool> used(candidates.size());
        backtracking(candidates, used, 0, target);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
