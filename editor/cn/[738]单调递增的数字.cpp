//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。 
//
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。） 
//
// 示例 1: 
//
// 输入: N = 10
//输出: 9
// 
//
// 示例 2: 
//
// 输入: N = 1234
//输出: 1234
// 
//
// 示例 3: 
//
// 输入: N = 332
//输出: 299
// 
//
// 说明: N 是在 [0, 10^9] 范围内的一个整数。 
// Related Topics 贪心 数学 
// 👍 222 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);

        int flag = strNum.size(); // 这里必须在最右边

        for (int i=strNum.size() - 1; i>0; i--) {
            if (strNum[i-1] > strNum[i]) {
                flag = i;
                strNum[i-1] --; // 这里做了降数
            }
        }

        for (int i=0; i<strNum.size(); i++) {
            if (i >= flag) {
                strNum[i] = '9';
            }
        }
        return stoi(strNum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
