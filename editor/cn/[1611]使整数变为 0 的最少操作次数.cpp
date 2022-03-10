//给你一个整数 n，你需要重复执行多次下述操作将其转换为 0 ： 
//
// 
// 翻转 n 的二进制表示中最右侧位（第 0 位）。 
// 如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的第 i 位。 
// 
//
// 返回将 n 转换为 0 的最小操作次数。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 0
//输出：0
// 
//
// 示例 2： 
//
// 
//输入：n = 3
//输出：2
//解释：3 的二进制表示为 "11"
//"11" -> "01" ，执行的是第 2 种操作，因为第 0 位为 1 。
//"01" -> "00" ，执行的是第 1 种操作。
// 
//
// 示例 3： 
//
// 
//输入：n = 6
//输出：4
//解释：6 的二进制表示为 "110".
//"110" -> "010" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
//"010" -> "011" ，执行的是第 1 种操作。
//"011" -> "001" ，执行的是第 2 种操作，因为第 0 位为 1 。
//"001" -> "000" ，执行的是第 1 种操作。
// 
//
// 示例 4： 
//
// 
//输入：n = 9
//输出：14
// 
//
// 示例 5： 
//
// 
//输入：n = 333
//输出：393
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 109 // 10^9
// 
// Related Topics 位运算 记忆化搜索 动态规划 
// 👍 42 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    unordered_map<string, int> mem;
    unordered_map<string, int> mem2;
public:
    int minimumOneBitOperations(int n) {
        /*
           心里路程
           1. 贪心
           101011 => 000000
           101011 => 1(10000) => 0(10000) => 0(00000)
        */

        string str = bitset<32>(n).to_string();
        return dfs(str);
    }

    int dfs(string n) {
        if (n == "0") return 0;
        if (n == "1") return 1;
        if (mem.find(n) != mem.end())
            return mem[n];

        if (n[0] == '0') return dfs(n.substr(1));

        string m = n.substr(1);
        string p = m;
        p[0] = '1';
        for (int i=1; i<p.size(); i++) {
            p[i] = '0';
        }
        mem[n] = helper(m) + 1 + dfs(p);
        return mem[n];
    }
    int helper(string n) {
        if (n == "0") return 1;
        if (n == "1") return 0;

        if (mem2.find(n) != mem2.end()) {
            return mem2[n];
        }

        if (n[0] == '1')
            mem2[n] = dfs(n.substr(1));
        else {
            string m = n.substr(1);
            string p = m;
            p[0] = '1';
            for (int i=1; i<p.size(); i++) {
                p[i] = '0';
            }
            mem2[n] = helper(m) + 1 + dfs(p);
        }
        return mem2[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
