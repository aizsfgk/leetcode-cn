//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 2.00000, n = 10
//输出：1024.00000
// 
//
// 示例 2： 
//
// 
//输入：x = 2.10000, n = 3
//输出：9.26100 
//
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2-2 = 1/22 = 1/4 = 0.25 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// -104 <= xn <= 104 
// 
//
// 
//
// 注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/ 
// Related Topics 递归 数学 
// 👍 308 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
    /*
        // 循环法
        // 快速幂方法
        int base = 1;
        for (int i=0; i<n; i++) {
            base = base * x;
        }
        return base;
    */
        // 特殊情况；只考虑n
        if (n == INT_MIN)
            return x == 1 || x == -1 ? 1 : 0; /// 足够小直接返回0了

        // 特殊情况处理:
        // 1 等于0
        if (n == 0)
            return 1.0;

        // 小于 0
        if (n < 0) // 将N转换为整数
            return myPow(1/x, -n);


        // 递归法
        // n 是 偶数
        if (n % 2 == 0) {
            return myPow(x * x, n/2);
        // n 是奇数
        } else {
            return myPow(x, n-1) * x;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
