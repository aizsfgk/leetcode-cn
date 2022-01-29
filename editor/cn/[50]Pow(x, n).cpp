//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn ）。 
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
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// -104 <= xn <= 104 
// 
// Related Topics 递归 数学 
// 👍 853 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >=0 ? multiQuick(x, N) : 1.0 / multiQuick(x, N);
    }

    /*
    当我们要计算 x^n 时，我们可以先递归地计算出 yxlfloorn2rfloor  ，其中 lfloorarfloor  表示对 a 进行下取整；

    根据递归计算的结果，如果 n 为偶数，那么 x^n = y^2；如果 n 为奇数，那么 xny2timesx  ；

    递归的边界为 n = 0，任意数的 0 次方均为 1。

    */
    double multiQuick(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }

        double y = multiQuick(x, n/2);

        return n % 2 == 0 ? y * y : y * y * x;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
