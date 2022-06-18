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
private:
    vector<string> ans;
    string path;

    // 想要每个都重复选择；则 从 0 索引 直接开始
    // 想要从中间的地方回溯； 则需要加 idx
    // 这是一个全排列的问题
    //
    void backtracking(const string &box, int left, int right, int n) {
        if (left > n || right > n || left < right)
            return;

        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        }

        for (int i=0; i < box.size(); i++) {
            path.push_back(box[i]);
            if (box[i] == '(') {
                backtracking(box,  left+1, right, n);
            } else {
                backtracking(box, left, right+1, n);
            }
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        /*
        if (n == 0) return {};
        if (n == 1) return {"()"};

        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        dp[1] = {"()"};


        // dp[i] : 括号对数是i的参数，结果集合是dp[i]

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
        */

        if (n == 0) return {};

        backtracking("()",  0, 0, n);
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
