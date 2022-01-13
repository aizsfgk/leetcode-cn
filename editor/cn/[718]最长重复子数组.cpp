//给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。 
//
// 
//
// 示例： 
//
// 输入：
//A: [1,2,3,2,1]
//B: [3,2,1,4,7]
//输出：3
//解释：
//长度最长的公共子数组是 [3, 2, 1] 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= len(A), len(B) <= 1000 
// 0 <= A[i], B[i] < 100 
// 
// Related Topics 数组 二分查找 动态规划 滑动窗口 哈希函数 滚动哈希 
// 👍 596 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 思路：
        //     子数组一定是连续的，对吗? 是的，就是连续子序列
        // dp[i][j] // 2个数组，所以需要 i, j
        // dp[i][j] => 以下表i为结尾的A和以下标j结尾的B,最长公共子数组长度为dp[i][j]
        //
        // 因为 dp[0][0] 不好解释，所以从 dp[1][1] 开始
        //

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        int ans = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                // 短一位的进行+1操作
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }

                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
