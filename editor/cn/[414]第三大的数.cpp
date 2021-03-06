//给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。 
//
// 
//
// 示例 1： 
//
// 
//输入：[3, 2, 1]
//输出：1
//解释：第三大的数是 1 。 
//
// 示例 2： 
//
// 
//输入：[1, 2]
//输出：2
//解释：第三大的数不存在, 所以返回最大的数 2 。
// 
//
// 示例 3： 
//
// 
//输入：[2, 2, 3, 1]
//输出：1
//解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
//此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 104 
// -231 <= nums[i] <= 231 - 1 
// 
//
// 
//
// 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？ 
// Related Topics 数组 排序 
// 👍 332 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        if (size == 2) {
            return max(nums[0], nums[1]);
        }

        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if (first > nums[i] && nums[i] > second) {
                third = second;
                second = nums[i];
            } else if (second > nums[i] && nums[i] > third) {
                third = nums[i];
            }
        }


        return third == LONG_MIN ? first : third;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
