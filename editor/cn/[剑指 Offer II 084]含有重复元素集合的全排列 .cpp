//给定一个可包含重复数字的整数集合 nums ，按任意顺序 返回它所有不重复的全排列。 
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
//
// 
//
// 注意：本题与主站 47 题相同： https://leetcode-cn.com/problems/permutations-ii/ 
// Related Topics 数组 回溯 👍 23 👎 0


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

        int layerUsed[21] = {0};
        for (int i=0; i<nums.size(); i++) {
            if (used[i] == 1) {
                continue;
            }

            if (layerUsed[nums[i]+10] == 1) { // 这个数已经使用过了; 则不再使用
                continue;
            }

            used[i] = 1;
            layerUsed[nums[i]+10] = 1;

            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();

            used[i] = 0;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return ans;

        vector<int> used(n);
        backtracking(nums, used);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
