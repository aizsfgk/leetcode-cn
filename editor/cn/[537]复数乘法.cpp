//复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件： 
//
// 
// 实部 是一个整数，取值范围是 [-100, 100] 
// 虚部 也是一个整数，取值范围是 [-100, 100] 
// i2 == -1 
// 
//
// 给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：num1 = "1+1i", num2 = "1+1i"
//输出："0+2i"
//解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
// 
//
// 示例 2： 
//
// 
//输入：num1 = "1+-1i", num2 = "1+-1i"
//输出："0+-2i"
//解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
// 
//
// 
//
// 提示： 
//
// 
// num1 和 num2 都是有效的复数表示。 
// 
// Related Topics 数学 字符串 模拟 
// 👍 91 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // 虚数乘法规则
        // (a+bi) (c+di) = (a*c - b*d) + (a*d + c*b)

        int a1,a2,b1,b2;

        string t = "";
        for (auto &c : num1) {
            if (c == '+') {
                a1 = stoi(t);
                t = "";
            } else if (c == 'i') {
                a2 = stoi(t);
                t = "";
            } else {
                t += c;
            }

        }

        for (auto &c : num2) {
            if (c == '+') {
                b1 = stoi(t);
                t = "";
            } else if (c == 'i') {
                b2 = stoi(t);
                t = "";
            } else { // 这里是else
                t += c;
            }
        }

        // 一定要小心啊
        return to_string(a1*b1 - a2*b2) + "+" + to_string(a1*b2 + a2*b1) + "i";

    }
};
//leetcode submit region end(Prohibit modification and deletion)
