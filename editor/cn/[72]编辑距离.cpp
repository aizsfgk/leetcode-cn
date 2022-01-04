//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
//
// 
//
// 提示： 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 和 word2 由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 
// 👍 2004 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 编辑距离
        // 思路：
        // 总共有6种操作方法，合并一下，剩3种
        // 1. 在单词A插入一个字符
        // 2. 在单词B插入一个字符
        // 3. 修改单词A的一个字符

        // 然后寻找状态转移方程式
        // min(a+1, b+1, c+1) // a,b,c 代表3种操作

        // D[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。

        int n = word1.size();
        int m = word2.size();

        if (n * m == 0) {
            return n + m;
        }

        // 初始化dp表
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // 处理边界 - 其中一个单词是空串
        for (int i=0; i<n+1; i++) {
            dp[i][0] = i;
        }

        for (int j=0; j<m+1; j++) {
            dp[0][j] = j;
        }

        // 计算dp值
        for (int i=1; i<n+1; i++) {
            for (int j=1; j<m+1; j++) {
                //
                int left = dp[i-1][j] + 1;
                int up = dp[i][j-1] + 1;
                int left_up = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1]) {
                    left_up += 1;
                }

                dp[i][j] = min(left, min(up, left_up));
            }
        }


        // 返回结果
        return dp[n][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
