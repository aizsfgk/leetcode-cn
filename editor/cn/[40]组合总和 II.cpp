//给你一个由候选元素组成的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
//
// candidates 中的每个元素在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
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
// Related Topics 数组 回溯 
// 👍 798 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int> &candidates, int target, int startIdx) {
        if (target < 0) {
            return;
        }

        // 所谓去重，其实就是使⽤过的元素不能重复选取
        //
        // 所以我们要去重的是同⼀树层上的“使⽤过”，同⼀树枝上的都是⼀个组合⾥的元素，不⽤去重。
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i=startIdx; i<candidates.size() && candidates[i] <= target; i++) {
            // used[i - 1] == true， 说明同⼀树⽀candidates[i - 1]使⽤过; 可以继续

            // used[i - 1] == false，说明同⼀树层candidates[i - 1]使⽤过
            if (i > 0 && candidates[i-1] == candidates[i] && used[i-1] == false) { /// 同一层使用过； 之所以要判断 used[i-1] 是因为单个组合里可以有重复元素
                continue;
            }

            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target - candidates[i], i+1);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0)
            return ans;


        used.resize(candidates.size(), false);

        sort(candidates.begin(), candidates.end());

        backtracking(candidates, target, 0);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
