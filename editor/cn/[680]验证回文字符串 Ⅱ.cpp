//给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "aba"
//输出: true
// 
//
// 示例 2: 
//
// 
//输入: s = "abca"
//输出: true
//解释: 你可以删除c字符。
// 
//
// 示例 3: 
//
// 
//输入: s = "abc"
//输出: false 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length <= 105 
// s 由小写英文字母组成 
// 
// Related Topics 贪心 双指针 字符串 
// 👍 442 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {


            left++;
            right--;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
