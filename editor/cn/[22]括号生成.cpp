//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 动态规划 回溯 
// 👍 2187 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        if (n == 1) return {"()"};

        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        dp[1] = {"()"};

        for (int i=2; i<=n; i++) {
            for (int j=0; j<i; j++) {
                for (auto p : dp[j]) {
                    for (auto q : dp[i-j-1]) {  // p = j; q+p = i-1 ==> q = i-j-1
                        string str = "(" + p + ")" + q;

                        dp[i].push_back(str);
                    }
                }
            }
        }

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
