//有效数字（按顺序）可以分成以下几个部分： 
//
// 
// 一个 小数 或者 整数 
// （可选）一个 'e' 或 'E' ，后面跟着一个 整数 
// 
//
// 小数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 下述格式之一：
// 
// 至少一位数字，后面跟着一个点 '.' 
// 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字 
// 一个点 '.' ，后面跟着至少一位数字 
// 
// 
// 
//
// 整数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 至少一位数字 
// 
//
// 部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7
//", "+6e-1", "53.5e93", "-123.456e789"] 
//
// 部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"] 
//
// 给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "0"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "e"
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：s = "."
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，或者点 '.' 。 
// 
// Related Topics 字符串 
// 👍 296 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isNumber(string s) {
        // 判断一个字符串数组是否是有效数
        //
        //
        int n = s.size();

        bool hasE = false;
        unordered_map<char, int> search;
        for (int i=0; i<n; i++) {
            if (!isValidChar(s[i])) {
                return false;
            }

            search[s[i]] ++;
        }

        if ((search['-'] > 1 ) || (search['+'] > 1 ) ||
            (search['.'] > 1) || search['e'] > 1 || search['E'] > 1 ||
                (search['+'] > 0 && search['-'] > 0) ) {
            return false;
        }








        return true;
    }

    bool isValidChar(char c) {
        if ((c >= '0' && c <= '9') || c == '.' || c == '-' || c == '+' || c == 'E' || c == 'e')
    }
};
//leetcode submit region end(Prohibit modification and deletion)
