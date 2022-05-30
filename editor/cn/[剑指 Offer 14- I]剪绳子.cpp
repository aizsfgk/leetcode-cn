//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
//请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
//。 
//
// 示例 1： 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36 
//
// 提示： 
//
// 
// 2 <= n <= 58 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
// Related Topics 数学 动态规划 
// 👍 436 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingRope(int n) {
        /*
            如何思考:
            dp[i] : i长度的绳子，修剪几段获得的最大乘积是多少?
            1. 1个 i 长度的绳子，一段剪成 j; 则另一端是 i-j长度； 乘积是： j * (i-j)
            2. 如果 (i - j) 长度的绳子需要再进行修建；则乘积是 j * dp[i-j]
            3. 我们遍历j可能的全部长度
            4. 求以上情况的最大值
        */
        vector<int> dp(n+1, 0);

        // base case 必须自己直接初始化
        dp[2] = 1;

        for (int i=3; i<=n; i++) {
            for (int j=1; j<i-1; j++) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
