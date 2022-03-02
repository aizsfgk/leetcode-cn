//给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。 
//
// “最近的”定义为两个整数差的绝对值最小。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = "123"
//输出: "121"
// 
//
// 示例 2: 
//
// 
//输入: n = "1"
//输出: "0"
//解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= n.length <= 18 
// n 只由数字组成 
// n 不含前导 0 
// n 代表在 [1, 1018 - 1] 范围内的整数 
// 
// Related Topics 数学 字符串 
// 👍 153 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string nearestPalindromic(string n) {
        /*
            返回最近的回文数

            6种情况:
                1. 9 , 1000 -> 999
                2. 10001 -> 9999
                3. 9999  -> 10001
                4. 12402 -> 12321  -1
                5. 12023 -> 12021  0
                6. 12099 -> 12121  +1

                // 123012 -> 123321
        */

        long len = n.size();
        long num = stol(n); // 字符串转换为long

        // 1
        if (num < 10 || num == pow(10, len-1)) {
            return to_string(num-1);
        }

        // 2
        if (num-1 == pow(10, len-1)) {
            return to_string(num-2);
        }

        // 3
        if (num+1 == pow(10, len)) {
            return to_string(num+2);
        }

        // 4/5/6
        // 拿到前一半的数字
        long firstHalfNum = stol(n.substr(0, (len+1)/2));

        string ans;
        long minDur = INT_MAX;
        for (int ele : {-1, 0, 1}) {

            string firstHalf = to_string(firstHalfNum + ele);
            string lastHalfTmp = firstHalf.substr(0, len/2); // 这里的一半必须是新的前半部分的一半
            string lastHalf(lastHalfTmp.rbegin(), lastHalfTmp.rend());

            string all = firstHalf + lastHalf;
            long curMin = abs(stol(all) - num);

            if (all != n && curMin < minDur) { // all != n 排除本身是回文串的情况
                minDur = curMin;
                ans = all;
            }
        }


        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
