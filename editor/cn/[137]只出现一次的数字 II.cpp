//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,2,3,2]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,0,1,0,1,99]
//输出：99
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 104 
// -231 <= nums[i] <= 231 - 1 
// nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 
// 
//
// 
//
// 进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？ 
// Related Topics 位运算 数组 
// 👍 815 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 整数范围
        int cnt[32] = {0};

        // 记录下所有数值的每一位共出现了多少次 1
        for (int x : nums) {
            for (int i=0; i<32; i++) {
                if (((x >>i ) & 1) == 1) {
                    cnt[i]++;
                }
            }
        }

        int ans = 0;
        // 再对 cnt[] 数组的每一位进行 mod 3 操作，重新拼凑出只出现一次的数值
        for (int i=0; i<32; i++) {
            if (((cnt[i] % 3) & 1) == 1) {
                ans += (1 << i);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
