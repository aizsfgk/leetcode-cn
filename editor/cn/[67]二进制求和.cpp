//给你两个二进制字符串，返回它们的和（用二进制表示）。 
//
// 输入为 非空 字符串且只包含数字 1 和 0。 
//
// 
//
// 示例 1: 
//
// 输入: a = "11", b = "1"
//输出: "100" 
//
// 示例 2: 
//
// 输入: a = "1010", b = "1011"
//输出: "10101" 
//
// 
//
// 提示： 
//
// 
// 每个字符串仅由字符 '0' 或 '1' 组成。 
// 1 <= a.length, b.length <= 10^4 
// 字符串如果不是 "0" ，就都不含前导零。 
// 
// Related Topics 位运算 数学 字符串 模拟 
// 👍 726 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addBinary(string a, string b) {
        // 思路
        // start

        string ans = "";
        int carry = 0;

        int n = a.size() - 1;
        int m = b.size() - 1;

        int a1,b1,sum = 0;

        while (n>=0 || m >=0 || carry) {
            a1 = n>=0 ? a[n] - '0' : 0;
            b1 = m>=0 ? b[m] - '0' : 0;

            sum  = a1 + b1 + carry;
            carry = sum/2;
            string tmpStr = sum%2 == 0 ? "0" : "1";
            ans.insert(0, tmpStr);

            n--;
            m--;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
