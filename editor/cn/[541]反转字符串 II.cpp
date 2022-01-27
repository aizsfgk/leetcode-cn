//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。 
//
// 
// 如果剩余字符少于 k 个，则将剩余字符全部反转。 
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abcdefg", k = 2
//输出："bacdfeg"
// 
//
// 示例 2： 
//
// 
//输入：s = "abcd", k = 2
//输出："bacd"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅由小写英文组成 
// 1 <= k <= 104 
// 
// Related Topics 双指针 字符串 
// 👍 245 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    void reverseS(string &str, int left, int right) {

        while (left < right) {
            char tmp = str[left];
            str[left] = str[right];
            str[right] = tmp;
            left++;
            right--;
        }
        return;
    }

public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int r = 0;
        for (int i=0; i<n; i = i + 2 * k) {
            r = i+k - 1;
            r = min(r, n-1);
            reverseS(s, i,  r);
        }

        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
