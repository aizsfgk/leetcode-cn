//给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。 
//
// 由于答案可能很大，因此 返回答案模 10^9 + 7 。 
//
// 
//
// 示例 1： 
//
// 
//输入：arr = [3,1,2,4]
//输出：17
//解释：
//子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
//最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。 
//
// 示例 2： 
//
// 
//输入：arr = [11,81,94,43,3]
//输出：444
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 3 * 104 
// 1 <= arr[i] <= 3 * 104 
// 
//
// 
// Related Topics 栈 数组 动态规划 单调栈 
// 👍 301 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // 疑问：为什么不是回溯?
        //
        // 这题怎么用单调栈解决啊?
        //
        //
        //
    }
};
//leetcode submit region end(Prohibit modification and deletion)
