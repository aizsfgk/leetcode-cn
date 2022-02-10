//给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于 n 的 最简 分数 。分数可以以 任意 顺序返回。 
//
// 
//
// 示例 1： 
//
// 输入：n = 2
//输出：["1/2"]
//解释："1/2" 是唯一一个分母小于等于 2 的最简分数。 
//
// 示例 2： 
//
// 输入：n = 3
//输出：["1/2","1/3","2/3"]
// 
//
// 示例 3： 
//
// 输入：n = 4
//输出：["1/2","1/3","1/4","2/3","3/4"]
//解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。 
//
// 示例 4： 
//
// 输入：n = 1
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 100 
// 
// Related Topics 数学 字符串 数论 
// 👍 46 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int gcd(int a, int b) { // 欧几里得法
        return b == 0 ? a : gcd(b, a % b);  // 求两个数的最大公约数是否是1
    }
    vector<string> simplifiedFractions(int n) {
        /*
            思路：

                数论的基本应用.
        */

        vector<string> ans;
        int i, j;
        // 暴力遍历求得分子 和 分母
        for (i=1; i < n; i++) {
            for (j=i+1; j<=n; j++) {
                if (gcd(i, j) == 1) ans.push_back(to_string(i) + "/" + to_string(j)); //
            }
        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
