//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。 
//
// 返回被除数 dividend 除以除数 divisor 得到的商。 
//
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2 
//
// 
//
// 示例 1: 
//
// 输入: dividend = 10, divisor = 3
//输出: 3
//解释: 10/3 = truncate(3.33333..) = truncate(3) = 3 
//
// 示例 2: 
//
// 输入: dividend = 7, divisor = -3
//输出: -2
//解释: 7/-3 = truncate(-2.33333..) = -2 
//
// 
//
// 提示： 
//
// 
// 被除数和除数均为 32 位有符号整数。 
// 除数不为 0。 
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。 
// 
// Related Topics 位运算 数学 
// 👍 826 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 思路
        // 不使用除法，模拟除法 --> 倍增乘法：
        // 每次用被除数减去[除数的最大的2^x]，这样可以极大地增加处理的速度

        // 溢出情况
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (divisor == 1)
            return dividend;

        // 记录结果的符号
        int sign = -1;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            sign = 1;
        }

        // 全部转成负数，防止溢出
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;

        int ans = 0;

        // 倍乘法; 比较的时候，与正数正好相反
        while(dividend <= divisor) {
            int tmp = divisor, count = 1;

            // 这里不要写成 tmp + tmp >= dividend, 可能溢出
            while (tmp >= dividend - tmp) {
                tmp += tmp;
                count += count;
            }


            dividend -= tmp;
            ans += count;
        }
        return sign < 0 ? -ans : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
