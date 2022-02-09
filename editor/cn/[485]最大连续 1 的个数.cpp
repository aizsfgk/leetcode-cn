//给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,0,1,1,1]
//输出：3
//解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
// 
//
// 示例 2: 
//
// 
//输入：nums = [1,0,1,1,0,1]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// nums[i] 不是 0 就是 1. 
// 
// Related Topics 数组 
// 👍 293 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();

        int ans = 0, num = 0;
        for (int i=0; i<n; i++) {
            if (1 & nums[i]) { // 只有0和1 最好使用位操作
                num++;
            } else {
                ans = max(ans, num);
                num = 0;
            }
        }

        return max(ans, num);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
