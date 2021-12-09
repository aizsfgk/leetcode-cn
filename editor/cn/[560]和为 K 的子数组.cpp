//给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,1], k = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3], k = 3
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2 * 104 
// -1000 <= nums[i] <= 1000 
// -107 <= k <= 107 
// 
// Related Topics 数组 哈希表 前缀和 
// 👍 1210 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //
    // 前缀和
    //
    // 暴力解法，跑不过
//    int subarraySum(vector<int>& nums, int k) {
//        int ans = 0;
//
//        int n = nums.size();
//
//        // 1. 构造前缀和
//        vector<int> preSum(n+1);
//        preSum[0] = 0;
//        for (int i=0; i<n; i++) {
//            preSum[i+1] = preSum[i] + nums[i];
//        }
//
//        // 2. 暴力破解
//        for (int i=1; i<=n; i++) {
//            for (int j=0; j<i; j++) {
//                if (preSum[i] - preSum[j] == k) {
//                    ans++;
//                }
//            }
//        }
//
//        return ans;
//    }

    // 优化解法
    int subarraySum(vector<int>& nums, int k) {

        // 前缀和Map
        unordered_map<int,int> preSumMap;
        // base
        preSumMap[0] = 1;

        // 元素个数
        int n = nums.size();

        // 答案 和 前缀和
        int ans = 0, sum = 0;
        for (int i=0; i<n; i++) {

            // 本次前缀和
            sum += nums[i];

            // 找到差值
            int dur = sum - k;

            // 如果找到有几个符合条件的j, 则更新答案
            if (preSumMap[dur]) {
                ans += preSumMap[dur];
            }

            // 开始先走这里， 计算有几个前缀j
            preSumMap[sum]++;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
