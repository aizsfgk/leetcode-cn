//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，
//等等。 
//
// 请写一个函数，求任意第n位对应的数字。 
//
// 
//
// 示例 1： 
//
// 输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
// 输入：n = 11
//输出：0 
//
// 
//
// 限制： 
//
// 
// 0 <= n < 2^31 
// 
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
// Related Topics 数学 二分查找 
// 👍 257 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNthDigit(int n) {
        int base = 1;
        int weight = 9;

        while (n > (long)base * weight) {
            n -= base * weight;
            base += 1;
            weight *= 10;
        }

        int index = n - 1; // 索引从0开始
        int start = pow(10, base - 1);
        int num = start + index / base;
        int bit = index % base;

        int digit = (num / (int)pow(10, base - 1 - bit)) % 10;
        return digit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
