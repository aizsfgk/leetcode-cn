//统计一个数字在排序数组中出现的次数。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [5,7,7,8,8,10], target = 8
//输出: 2 
//
// 示例 2: 
//
// 
//输入: nums = [5,7,7,8,8,10], target = 6
//输出: 0 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums 是一个非递减数组 
// -109 <= target <= 109 
// 
//
// 
//
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-
//position-of-element-in-sorted-array/ 
// Related Topics 数组 二分查找 
// 👍 320 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        int l = 0, r = nums.size()-1;
        while (l <= r && (nums[l] != target || nums[r] != target)) { // 必须加上 <=
            if (nums[l] != target) {
                l++;
            }
            if (nums[r] != target) {
                r--;
            }
        }
        return l > r ? 0 : r - l + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
