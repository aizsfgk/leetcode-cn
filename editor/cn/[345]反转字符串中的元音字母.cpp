//给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。 
//
// 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "hello"
//输出："holle"
// 
//
// 示例 2： 
//
// 
//输入：s = "leetcode"
//输出："leotcede" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 105 
// s 由 可打印的 ASCII 字符组成 
// 
// Related Topics 双指针 字符串 
// 👍 235 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    bool isYuan(char a) {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'
        || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U';
    }
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (!isYuan(s[left]) && left < right) {
                left++;
            }

            while (!isYuan(s[right]) && left < right) {
                right--;
            }

            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
