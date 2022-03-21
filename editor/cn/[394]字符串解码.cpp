//给定一个经过编码的字符串，返回它解码后的字符串。 
//
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。 
//
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。 
//
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "3[a]2[bc]"
//输出："aaabcbc"
// 
//
// 示例 2： 
//
// 
//输入：s = "3[a2[c]]"
//输出："accaccacc"
// 
//
// 示例 3： 
//
// 
//输入：s = "2[abc]3[cd]ef"
//输出："abcabccdcdcdef"
// 
//
// 示例 4： 
//
// 
//输入：s = "abc3[cd]xyz"
//输出："abccdcdcdxyz"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 30 
// s 由小写英文字母、数字和方括号 '[]' 组成 
// s 保证是一个 有效 的输入。 
// s 中所有整数的取值范围为 [1, 300] 
// 
// Related Topics 栈 递归 字符串 
// 👍 1024 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string decodeString(string s) {
        string res;
        int num = 0;
        int n = s.size();
        stack<int> nums;
        stack<string> sStk;

        for (int i=0; i<n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                res = res + s[i];
            } else if (s[i] == '[') {
                nums.push(num);
                num = 0;
                sStk.push(res);
                res = "";
            } else { // 遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
                int times = nums.top(); nums.pop();
                for (int j=0; j<times; j++) {
                    sStk.top() += res;
                }

                /*
                   之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                   若是左括号，res会被压入strs栈，作为上一层的运算
                */
                res = sStk.top();

                sStk.pop();
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
