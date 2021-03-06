//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的
//房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,3,2]
//输出：3
//解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,1]
//输出：4
//解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 1000 
// 
// Related Topics 数组 动态规划 
// 👍 884 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
/*
    int rob(vector<int>& nums) {
        // 思路： 1. 首尾都不偷
        //       2. 偷首1，不偷尾1
        //       3. 不偷首1， 偷尾1
        // 注意：2，3都包含情况1
        // dp[i] => 含有i个房子，最多拿多少钱
        //
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        if (size == 2)
            return max(nums[0], nums[1]);

        int r1 = startSteal(nums, 0, nums.size() - 2); // 不偷尾
        int r2 = startSteal(nums, 1, nums.size() - 1); // 不偷头

        return max(r1, r2);
    }

    // 单独开偷
    int startSteal(vector<int> &nums, int start, int end) {
        // 只有一个元素
        if (end == start) {
            return nums[start];
        }

        vector<int> dp(nums.size());

        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        for (int i= start+2; i<=end; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[end];
    }

*/
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        return max(myRob(nums, 0, n-2), myRob(nums, 1, n-1));
    }

    int myRob(const vector<int>& nums, int start, int end) {

        int prev = 0,cur = 0,tmp;
        for (int i=start; i<=end; i++) {
            tmp = cur;
            cur = max(prev + nums[i], cur);
            prev = tmp;
        }
        return cur;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
