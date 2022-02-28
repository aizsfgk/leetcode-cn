//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
// 
// 
// Related Topics 位运算 数组 回溯 
// 👍 744 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int> &nums, int idx) {
        ans.push_back(path);

        // 终止条件
        if (idx >= nums.size()) {
            return;
        }

        int used[21] = {0};
        for (int i=idx; i<nums.size(); i++) {
            if (used[nums[i]+10] != 0) {
                continue;
            }

            used[nums[i]+10] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0)
            return ans;

        sort(nums.begin(), nums.end()); // 排序很重要；为啥不排序就会出现重复呢???

        backtracking(nums, 0);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
