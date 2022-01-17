//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
// Related Topics 数组 回溯 
// 👍 1730 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(const vector<int> &nums, vector<int> &used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (used[i] == 1) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = 1;
            backtracking(nums, used);
            used[i] = 0;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 全排列问题
        if (nums.size() == 0)
            return ans;

        vector<int> used(nums.size(), 0);
        backtracking(nums,used);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
