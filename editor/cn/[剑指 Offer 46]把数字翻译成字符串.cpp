//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可
//能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。 
//
// 
//
// 示例 1: 
//
// 输入: 12258
//输出: 5
//解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi" 
//
// 
//
// 提示： 
//
// 
// 0 <= num < 231 
// 
// Related Topics 字符串 动态规划 
// 👍 446 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int translateNum(int num) {
        // 如何进行拆分； 有点像是 回溯的拆分字符串
        string src = to_string(num);
        int n = src.size();

        // a 是第一个 now；b 是第二个 prev
//        int a = 1, b = 1;

        int prev = 1, now = 1;
        for (int i=2; i<=n; i++) {
            string preStr = src.substr(i-2, 2);

            int newNow = preStr >= "10" && preStr <= "25" ? prev + now : now;
            prev = now;
            now = newNow;
        }
        return now;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
