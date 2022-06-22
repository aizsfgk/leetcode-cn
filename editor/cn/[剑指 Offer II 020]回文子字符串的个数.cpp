//给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 
//输入：s = "aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 由小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 647 题相同：https://leetcode-cn.com/problems/palindromic-substrings/ 
// Related Topics 字符串 动态规划 👍 53 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        // 和最长回文子串的思路一致；使用动态规划
        int n = s.size();
        if (n == 0) return 0;

        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(n, 0)); // 以 i ~ j 为区间的字符串是否是回文串



        // 两个迭代
        for (int j=0; j<n; j++) {
            for (int i=0; i<=j; i++) {
                if (s[i] == s[j]) {
                    if (j-i < 3) {
                        dp[i][j] = 1;
                        ans++;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                        if (dp[i][j]) ans++;
                    }

                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
