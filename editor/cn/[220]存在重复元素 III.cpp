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
// 0 <= nums.length <= 2 * 104 
// -231 <= nums[i] <= 231 - 1 
// 0 <= k <= 104 
// 0 <= t <= 231 - 1 
// 
// Related Topics 数组 桶排序 有序集合 排序 滑动窗口 
// 👍 548 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // 暴力方法超时了
        /*
        map<long long, int> myMap;
        long long start = 0, end = 0;
        for (int i=0; i<nums.size(); i++) {
            start = (long long) -t + nums[i];
            end = (long long) t + nums[i];

            while (start <= end) {
                auto it = myMap.find(start);
                if (it != myMap.end()) {
                    if (abs( i - it->second) <=k) {
                        return true;
                    }
                }
                start++;
            }
            myMap[nums[i]] = i;
        }
        return false;
        */

        /*
        // 滑动窗口: 这个逻辑是有问题的
        int left = 0, right =0;
        while (right < nums.size()) {
            right++;

            if (right - left <= k) {
                if (abs((long)nums[left] - nums[right]) <= t) {
                    return true;
                }
            } else {
                left ++;
                while(left < right) {
                    if (abs((long)nums[left] - nums[right]) <= t) {
                        return true;
                    }
                    left++;
                }
            }
        }

        return false;

        */

        set<long> mySet;
        for (int i=0; i<nums.size(); i++) {
            // lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。
            // 也就是说，使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素。
            // lower_bound 这个函数太好用了 >=
            //
            //  abs(a - b) >= t ===>  a - t <= b <= a + t
            //
            auto lb = mySet.lower_bound((long)nums[i] - t);
            if (lb != mySet.end() && *lb <= (long)nums[i] +t ) return true;

            mySet.insert(nums[i]);
            if (i >= k) { // 没有返回true, 则第一个元素，可以剔除了
                mySet.erase(nums[i-k]);
            }
        }

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
