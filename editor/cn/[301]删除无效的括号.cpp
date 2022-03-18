//给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。 
//
// 返回所有可能的结果。答案可以按 任意顺序 返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()())()"
//输出：["(())()","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：s = "(a)())()"
//输出：["(a())()","(a)()()"]
// 
//
// 示例 3： 
//
// 
//输入：s = ")("
//输出：[""]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 25 
// s 由小写英文字母以及括号 '(' 和 ')' 组成 
// s 中至多含 20 个括号 
// 
// Related Topics 广度优先搜索 字符串 回溯 
// 👍 660 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    unordered_set<string> memo;
    int n;
    int maxLen;
    int len;
    string ori_s;
public:
    vector<string> removeInvalidParentheses(string s) {
        /*
        思路：
        */
        ori_s = s;
        n = s.size();
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') r++;
        }

        len = 0;
        maxLen = min(l, r);
        dfs(0, "", 0);

        vector<string> ans;
        for (auto it=memo.begin(); it != memo.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }

    void dfs(int idx, string cur, int score) {
        if (score < 0 || score > maxLen ) return; // 是否有效转换为数字

        if (idx == n) {
            if (score == 0 && cur.size() >= len) {
                if (cur.size() > len)
                    memo.clear();
                len = cur.size();
                memo.insert(cur);
            }
            return;
        }

        char c = ori_s[idx];
        string tmp(1, c);
        string newStr = cur + tmp;
        if (c == '(') {
            dfs(idx+1, newStr, score+1);
            dfs(idx+1, cur, score);
        } else if (c == ')') {
            dfs(idx+1, newStr, score-1);
            dfs(idx+1, cur, score);
        } else {
            dfs(idx+1, newStr, score);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
