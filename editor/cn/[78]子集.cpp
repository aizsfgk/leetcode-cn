//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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
// nums 中的所有元素 互不相同 
// 
// Related Topics 位运算 数组 回溯 
// 👍 1448 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path; // 路径

    void backtracking(const vector<int> &nums, int startIdx) {
        // 所有的节点都收集
        // 收集自己
        ans.push_back(path);

        // 中止条件
        if (startIdx >= nums.size()) {
            return;
        }

        // 回溯
        for (int i=startIdx; i<nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return ans;

        backtracking(nums, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
