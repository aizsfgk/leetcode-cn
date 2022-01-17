//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。 
//
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,6,7,7]
//输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,4,3,2,1]
//输出：[[4,4]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 15 
// -100 <= nums[i] <= 100 
// 
// Related Topics 位运算 数组 哈希表 回溯 
// 👍 382 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void backtracking(const vector<int> &nums, int startIdx, int preNum) {

        // 至少为2
        if (path.size() > 1) {
            ans.push_back(path);
        }

        if (startIdx >= nums.size()) {
            return;
        }

        int used[201] = {0};
        for (int i=startIdx; i<nums.size(); i++) {

            if (nums[i] >= preNum && used[nums[i]+100] != 1) { // 大于前一个值，并且同层没有使用过该数
                path.push_back(nums[i]);
            } else {
                continue;
            }
            // 记录
            used[nums[i]+100] = 1;

            backtracking(nums, i+1, nums[i]);

            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // 递增子序列
        if (nums.size() <= 1)
            return ans;

        backtracking(nums, 0, INT_MIN);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
