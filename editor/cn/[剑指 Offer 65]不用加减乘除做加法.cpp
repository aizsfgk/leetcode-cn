//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。 
//
// 
//
// 示例: 
//
// 输入: a = 1, b = 1
//输出: 2 
//
// 
//
// 提示： 
//
// 
// a, b 均可能是负数或 0 
// 结果不会溢出 32 位整数 
// 
// Related Topics 位运算 数学 
// 👍 319 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int add(int a, int b) {
        /*
            思路： 考察的是位运算 NO

            a 做为 base
            b 作为 relative
        */
        while (b) {
            int carry = a & b; // 计算 进位
            a = a ^ b;         // 计算 非进位
            b = (unsigned) carry << 1;
        }
        return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
