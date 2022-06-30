//正整数 n 代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
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
//
// 
//
// 注意：本题与主站 22 题相同： https://leetcode-cn.com/problems/generate-parentheses/ 
// Related Topics 字符串 动态规划 回溯 👍 38 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> ans;
    string path;

    void backtracking(const string &str, int n, int left, int right) {
        // 剪枝
        if (right > left || left > n || right > n) {
            return;
        }

        // 终止条件
        if (path.size() == 2*n) {
            ans.push_back(path);
            return;
        }

        // 对元素进行选择
        for (int i=0; i<str.size(); i++) {
            path.push_back(str[i]);
            if (str[i] == '(') {
                backtracking(str, n, left+1, right);
            } else {
                backtracking(str, n, left, right+1);
            }
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtracking("()", n, 0, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
