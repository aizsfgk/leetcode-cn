//给你一个整数 n ，请你找出并返回第 n 个 丑数 。 
//
// 丑数 就是只包含质因数 2、3 和/或 5 的正整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 10
//输出：12
//解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
//解释：1 通常被视为丑数。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 1690 
// 
// Related Topics 哈希表 数学 动态规划 堆（优先队列） 
// 👍 851 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 暴力解法
    int nthUglyNumber(int n) {
        vector<int> nums;
        // 只包含 2，3，5 因子
        for (long a=1; a<=INT_MAX; a *=2)
            for (long b=a; b<=INT_MAX; b *=3)
                for (long c=b; c<=INT_MAX; c*=5)
                    nums.push_back(c);

        sort(nums.begin(), nums.end());
        return nums[n-1];
    }
    // 小根堆


};
//leetcode submit region end(Prohibit modification and deletion)
