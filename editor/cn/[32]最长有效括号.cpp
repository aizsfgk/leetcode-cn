//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 104 
// s[i] 为 '(' 或 ')' 
// 
// 
// 
// Related Topics 栈 字符串 动态规划 
// 👍 1567 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 1) {
            return s.size();
        }

        int ans = 0, start = 0;
        stack<int> st;

        for (int i=0; i<s.size(); i++) {

            if (s[i] == '(') {
                st.push(i);
            } else {

                if (!st.empty()) {
                    st.pop();

                    // 为空， 则表明是最长的合法串
                    if (st.empty()) {
                        ans = max(ans, i - start + 1);
                    } else {
                        // 最左边是栈顶元素的下一个元素
                        ans = max(ans, i - st.top()); // i - st.top() -1+1 ==> i - stop();
                    }

                } else {
                    start = i+1;
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
