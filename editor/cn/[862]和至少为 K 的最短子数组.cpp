//给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，并返回该子数组的长度。如果不存在这样的 子数组 ，返回 
//-1 。 
//
// 子数组 是数组中 连续 的一部分。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1], k = 1
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2], k = 4
//输出：-1
// 
//
// 示例 3： 
//
// 
//输入：nums = [2,-1,2], k = 3
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -105 <= nums[i] <= 105 
// 1 <= k <= 109  # k > 0
// 
// Related Topics 队列 数组 二分查找 前缀和 滑动窗口 单调队列 堆（优先队列） 
// 👍 357 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // 思路:
        //
        // 前缀和 + 单调队列
        //
        if (nums.empty())
            return -1;

        // 多一个元素; 0索引是无效元素
        vector<long long> preSum(nums.size()+1, 0);
        // 前缀和
        // 0 < n <= nums.size()
        for (int i=1; i<=nums.size(); i++) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }

        // 答案默认是最大值
        int ans = INT_MAX;
        // 单调队列
        deque<int> monotoneQueue;
        for (int i=0; i<=nums.size(); i++) {

            // 当前索引的前缀和
            long long a = preSum[i]; // 前缀和

            // 删掉 queue中可能的头
            // 前缀和小于等于最大的元素，则单调队列，一直弹出
            // 因为 k > 0
            while (!monotoneQueue.empty() && a <= preSum[monotoneQueue.back()]) {
                monotoneQueue.pop_back();
            }

            // 当前的前缀和 - 最小的前缀和 大于 等于 k
            //
            while (!monotoneQueue.empty() && a - preSum[monotoneQueue.front()] >= k) {

                // 更新答案
                ans = min(ans, i - monotoneQueue.front());
                monotoneQueue.pop_front();
            }

            // 存储当前前缀和的索引
            monotoneQueue.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
