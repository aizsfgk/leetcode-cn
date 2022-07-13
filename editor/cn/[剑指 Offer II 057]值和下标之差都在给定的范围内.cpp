//给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= 
//t ，同时又满足 abs(i - j) <= k 。 
//
// 如果存在则返回 true，不存在返回 false。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3,1], k = 3, t = 0
//输出：true 
//
// 示例 2： 
//
// 
//输入：nums = [1,0,1,1], k = 1, t = 2
//输出：true 
//
// 示例 3： 
//
// 
//输入：nums = [1,5,9,1,5,9], k = 2, t = 3
//输出：false 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 2 * 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 0 <= k <= 10⁴ 
// 0 <= t <= 2³¹ - 1 
// 
//
// 
//
// 注意：本题与主站 220 题相同： https://leetcode-cn.com/problems/contains-duplicate-iii/ 
// Related Topics 数组 桶排序 有序集合 排序 滑动窗口 👍 47 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        /*
        // 暴力会超时
        int n = nums.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                long long a = nums[i];
                long long b = nums[j];
                if (abs(a-b) <= t && abs(i-j) <= k) {
                    return true;
                }
            }
        }

        return false;
        */

        int n = nums.size();
        set<int> window;
        for (int i=0; i<n; i++) {
            // 我们检查窗口中是否存在元素落在区间 [x−t,x+t] 中即可
            // 二分查找
            // 一个数 >= nums[i] - t
            auto it = window.lower_bound(max(nums[i], INT_MIN+t)-t);

            // 存在这个数，并且这个数 <= nums[i] - t
            if ( it != window.end() && *it <= min(nums[i], INT_MAX-t)+t ) {
                return true;
            }

            window.insert(nums[i]);

            if (i>=k) {
                window.erase(nums[i-k]);
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
