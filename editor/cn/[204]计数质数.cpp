//给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 10
//输出：4
//解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 
//
// 示例 2： 
//
// 
//输入：n = 0
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：n = 1
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 5 * 106 
// 
// Related Topics 数组 数学 枚举 数论 
// 👍 833 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 思路1： 暴力: 会超时
/*
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i=2; i<n; i++) {
            if (isPrime(i)) {
                cnt++;
            }
        }

        return cnt;
    }

    bool isPrime(int x) {
        for (int i=2; i<x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }


};
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n);
        int cnt = 0;
        for (int i=2; i<n; i++) {
            if (!primes[i]) {
                cnt++;
                for (int j=i*2; j<n; j+=i) { // 埃筛法
                    primes[j] = true;
                }
            }
        }

        return (int)cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
