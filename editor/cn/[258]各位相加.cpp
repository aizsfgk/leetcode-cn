//给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。 
//
// 示例: 
//
// 输入: 38
//输出: 2 
//解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
// 
//
// 进阶: 
//你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？ 
// Related Topics 数学 数论 模拟 
// 👍 397 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {
public:
    int addDigits(int num) {
        // 思路：
        // 将所有元素，9个一打包，然后相+； 但解决不了正好是9的倍数的问题
        // 所以进行 -1 + 1 操作

        return (num - 1) % 9  + 1;
    }
};
*/
/* 使用迭代法解决这个问题 */
class Solution {
public:
    int addDigits(int num) {
        // 迭代法
        int sum;
        while (num >= 10) {
            sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
