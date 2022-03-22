//给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。 
//
// 如果小数部分为循环小数，则将循环的部分括在括号内。 
//
// 如果存在多个答案，只需返回 任意一个 。 
//
// 对于所有给定的输入，保证 答案字符串的长度小于 104 。 
//
// 
//
// 示例 1： 
//
// 
//输入：numerator = 1, denominator = 2
//输出："0.5"
// 
//
// 示例 2： 
//
// 
//输入：numerator = 2, denominator = 1
//输出："2"
// 
//
// 示例 3： 
//
// 
//输入：numerator = 2, denominator = 3
//输出："0.(6)"
// 
//
// 示例 4： 
//
// 
//输入：numerator = 4, denominator = 333
//输出："0.(012)"
// 
//
// 示例 5： 
//
// 
//输入：numerator = 1, denominator = 5
//输出："0.2"
// 
//
// 
//
// 提示： 
//
// 
// -231 <= numerator, denominator <= 231 - 1 
// denominator != 0 
// 
// Related Topics 哈希表 数学 字符串 
// 👍 369 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 转 long 计算，防止溢出
        long long a = numerator, b = denominator;
        // 如果本身能够整除，直接返回计算结果
        if ( a % b == 0) return to_string(a/b);

        string ans;
        // 如果其一为负数，先追加负号
        if (a * b < 0) ans.push_back('-');

        a = abs(a); b = abs(b);
        // 计算小数点前的部分，并将余数赋值给 a
        ans += to_string(a/b) + ".";

        a %= b;

        unordered_map<long long, int> memo;
        while (a != 0) {
            //
            // 记录当前余数所在答案位置，并继续模拟除法运算
            //

            memo[a] = ans.size();
            a *= 10;
            ans += to_string(a/b);
            a %= b;

            // 如果当前余数之前出现过，则将 [出现位置 到 当前位置] 的部分抠出来（循环小数部分）
            if (memo.count(a) > 0) {
                int u = memo[a];
                return ans.substr(0, u) + "(" + ans.substr(u) + ")";
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
