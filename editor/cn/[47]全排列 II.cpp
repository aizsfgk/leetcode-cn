//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 数组 回溯 
// 👍 914 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<int> used) {
        // 符合条件的全排列
        if (nums.size() == path.size()) {
            ans.push_back(path);
            return;
        }

        // 同层是否使用过?
        int layerUsed[21] = {0};

        // 开始回溯
        for (int i=0; i<nums.size(); i++) {
            // 使用过的数字（使用过的索引位置），跳过
            if (used[i] == 1) {
                continue;
            }

            // 同层使用过的数字跳过，防止重复数字
            if (layerUsed[nums[i] + 10] == 1) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = 1;
            layerUsed[nums[i] + 10] = 1;
            backtracking(nums, used);
            used[i] = 0;
            path.pop_back();
        }

    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0)
            return ans;

        vector<int> used(nums.size(), 0);
        backtracking(nums, used);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
