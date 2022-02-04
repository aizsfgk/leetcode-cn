//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 示例 3： 
//
// 
//输入：s = "a"
//输出："a"
// 
//
// 示例 4： 
//
// 
//输入：s = "ac"
//输出："a"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母（大写和/或小写）组成 
// 
// Related Topics 字符串 动态规划 
// 👍 4460 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 最长回文子串
    // 最长回文子串，使用动态规划
    // dp[i][j] = 以索引 i - j 的子串的最长回文串长度是dp[i][j]
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        // dp table
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case
        for (int i=0; i<n; i++) {
            dp[i][i] = 1;
        }

        int start = 0, max = 1;
        // 状态转换方程
        // f(i,j) = { 1, len<2; len = j-i+1 }
        //        = { 1, s[i] == s[j] && f(i+1, j-1) == 1;
        //            else 0; len >= 2 }
        // for loop
        // 遍历所有子串; 遍历所有子串的一个模板
        for (int j=1; j<n; j++) {
            for (int i=0; i<j; i++) {

                // 左右边界字符相等
                if (s[i] == s[j]) {
                    // (j-1) - (i+1) + 1 < 2 ==> j-i < 3
                    if (j-i < 3) { // 保证base case 满足
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                // 求结果
                if (dp[i][j] == 1 && j-i+1 > max) {
                    start = i;
                    max = j-i+1;
                }
            }
        }

        return s.substr(start, max);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
