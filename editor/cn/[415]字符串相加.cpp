//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。 
//
// 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。 
//
// 
//
// 示例 1： 
//
// 
//输入：num1 = "11", num2 = "123"
//输出："134"
// 
//
// 示例 2： 
//
// 
//输入：num1 = "456", num2 = "77"
//输出："533"
// 
//
// 示例 3： 
//
// 
//输入：num1 = "0", num2 = "0"
//输出："0"
// 
//
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num1.length, num2.length <= 104 
// num1 和num2 都只包含数字 0-9 
// num1 和num2 都不包含任何前导零 
// 
// Related Topics 数学 字符串 模拟 
// 👍 498 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        // 两字符串相加

        int n = num1.size() - 1;
        int m = num2.size() - 1;
        int carry = 0;
        string ans = "";
        while (n>=0 || m >= 0 || carry) {
            int one = n >= 0 ? num1[n] - '0' : 0;
            int two = m >= 0 ? num2[m] -  '0' : 0;

            int sum = one + two + carry;
            carry = sum / 10;

            char tmp = (sum % 10) + '0';
            ans.insert(0, 1, tmp);
            n--;
            m--;
        }

        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
