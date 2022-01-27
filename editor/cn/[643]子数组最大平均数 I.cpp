//给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。 
//
// 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。 
//
// 任何误差小于 10-5 的答案都将被视为正确答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,12,-5,-6,50,3], k = 4
//输出：12.75
//解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
// 
//
// 示例 2： 
//
// 
//输入：nums = [5], k = 1
//输出：5.00000
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// 1 <= k <= n <= 105 
// -104 <= nums[i] <= 104 
// 
// Related Topics 数组 滑动窗口 
// 👍 219 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 思路：
    // 以 k 为窗口大小，一直滑动；求得最大平均数
    //
    double findMaxAverage(vector<int>& nums, int k) {
        double window = 0.0;
        int n = nums.size();


        double ans = -100000;
        for (int i=0; i<k; i++) {
            window += (double)nums[i];
        }

        double tmp = window/k;
        ans = max(tmp, ans);

        for (int i=k; i<n; i++) {
            // 减去上一个元素
            window = window - (double)nums[i-k];
            // 加上下一个元素
            window = window + (double)nums[i];
            ans = max(ans, window/k);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
