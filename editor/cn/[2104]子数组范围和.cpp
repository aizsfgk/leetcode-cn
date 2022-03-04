//给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。 
//
// 返回 nums 中 所有 子数组范围的 和 。 
//
// 子数组是数组中一个连续 非空 的元素序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：4
//解释：nums 的 6 个子数组如下所示：
//[1]，范围 = 最大 - 最小 = 1 - 1 = 0 
//[2]，范围 = 2 - 2 = 0
//[3]，范围 = 3 - 3 = 0
//[1,2]，范围 = 2 - 1 = 1
//[2,3]，范围 = 3 - 2 = 1
//[1,2,3]，范围 = 3 - 1 = 2
//所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4 
//
// 示例 2： 
//
// 
//输入：nums = [1,3,3]
//输出：4
//解释：nums 的 6 个子数组如下所示：
//[1]，范围 = 最大 - 最小 = 1 - 1 = 0
//[3]，范围 = 3 - 3 = 0
//[3]，范围 = 3 - 3 = 0
//[1,3]，范围 = 3 - 1 = 2
//[3,3]，范围 = 3 - 3 = 0
//[1,3,3]，范围 = 3 - 1 = 2
//所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
// 
//
// 示例 3： 
//
// 
//输入：nums = [4,-2,-3,4,1]
//输出：59
//解释：nums 中所有子数组范围的和是 59
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// -109 <= nums[i] <= 109 
// 
//
// 
//
// 进阶：你可以设计一种时间复杂度为 O(n) 的解决方案吗？ 
// Related Topics 栈 数组 单调栈 
// 👍 62 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// 暴力破解
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        long long ans = 0;

        for (int i=0; i<n; i++) {
            long long curMax = 0;
            long long minV = INT_MAX;
            long long maxV = INT_MIN;
            for (int j=i; j<n; j++) {
                minV = min(minV, (long long)nums[j]);
                maxV = max(maxV, (long long)nums[j]);
                curMax += abs(maxV - minV);
            }
            ans += curMax;
        }
        return ans;
    }
};
*/
// 单调栈解决法
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size(); // 元素个数
        vector<int> lSmall(n);
        vector<int> rSmall(n);
        vector<int> lLarge(n);
        vector<int> rLarge(n);

        // 根据乘法原理，区间个数为 (i - p) * (q - i) 个
        // [2, 3, 5, 4, 10, 2] => 4
        //
        //
        // > 或者 >= 这是考虑了相同元素???
        stack<int> monoStk;
        for (int i=0; i<n; i++) {
            while (!monoStk.empty() && nums[monoStk.top()] >= nums[i]) {
                monoStk.pop();
            }
            lSmall[i] = monoStk.empty() ? -1 : monoStk.top();
            monoStk.push(i);
        }

        stack<int>().swap(monoStk);
        for (int i=n-1; i>=0; i--) {
            while (!monoStk.empty() && nums[monoStk.top()] > nums[i]) {
                monoStk.pop();
            }
            rSmall[i] = monoStk.empty() ? n : monoStk.top();
            monoStk.push(i);
        }


        stack<int>().swap(monoStk);
        for (int i=0; i<n; i++) {
            while (!monoStk.empty() && nums[monoStk.top()] <= nums[i]) {
                monoStk.pop();
            }
            lLarge[i] = monoStk.empty() ? -1 : monoStk.top();
            monoStk.push(i);
        }

        stack<int>().swap(monoStk);
        for (int i=n-1; i>=0; i--) { // 是++, 还是--? 这很重要
            while (!monoStk.empty() && nums[monoStk.top()] < nums[i]) {
                monoStk.pop();
            }
            rLarge[i] = monoStk.empty() ? n : monoStk.top();
            monoStk.push(i);
        }

        long long ans = 0;
        for (int i=0; i<n; i++) {
            ans += nums[i] * 1L *(i-lLarge[i]) * (rLarge[i] - i);
            ans -= nums[i] * 1L * (i-lSmall[i]) * (rSmall[i] - i);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
