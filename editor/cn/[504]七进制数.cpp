//给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。 
//
// 
//
// 示例 1: 
//
// 
//输入: num = 100
//输出: "202"
// 
//
// 示例 2: 
//
// 
//输入: num = -7
//输出: "-10"
// 
//
// 
//
// 提示： 
//
// 
// -107 <= num <= 107 
// 
// Related Topics 数学 
// 👍 135 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convertToBase7(int num) {
        // 特殊情况处理
        if (num == 0) {
            return "0";
        }

        // 负数转换为正数
        bool flag = false;
        if (num < 0) {
            flag = true;
            num = -num;
        }

        // 除数取余法
        int val = 0;
        string ans = "";
        while (num) {
            val = num % 7;
            num = num / 7;
            ans.push_back(val + '0');
        }
        if (flag) {
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
