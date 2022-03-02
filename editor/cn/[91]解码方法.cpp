//一条包含字母 A-Z 的消息通过以下映射进行了 编码 ： 
//
// 
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26" 
//
// 要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为： 
//
// 
// "AAJF" ，将消息分组为 (1 1 10 6) 
// "KJF" ，将消息分组为 (11 10 6) 
// 
//
// 注意，消息不能分组为 (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。 
//
// 给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。 
//
// 题目数据保证答案肯定是一个 32 位 的整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "12"
//输出：2
//解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
// 
//
// 示例 2： 
//
// 
//输入：s = "226"
//输出：3
//解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
// 
//
// 示例 3： 
//
// 
//输入：s = "0"
//输出：0
//解释：没有字符映射到以 0 开头的数字。
//含有 0 的有效映射是 'J' -> "10" 和 'T'-> "20" 。
//由于没有字符，因此没有有效的方法对此进行解码，因为所有数字都需要映射。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 100 
// s 只包含数字，并且可能包含前导零。 
// 
// Related Topics 字符串 动态规划 
// 👍 1094 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// 使用回溯法，会超时
// length == 100
class Solution {
private:
    int ans = 0;

    // 类似一个切割问题
    void backtracking(string &s, int idx) {
        if (idx >= s.size()) {
            ans++;
            return;
        }

        for (int i=idx; i<s.size(); i++) {
            string sub = s.substr(idx, i-idx+1);
            if (isValid(sub)) {
                backtracking(s, i+1);
            }
        }
    }

    bool isValid(string &s) {
        if (s.empty()) {
            return false;
        }

        if (s[0] == '0') {
            return false;
        }

        if (s.size() > 3)
            return false;

        int n = stol(s);
        return n >= 1 && n <= 26;
    }
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        backtracking(s, 0);
        return ans;
    }
};
*/
class Solution {
public:
    int numDecodings(string s) {
        // 1 -> 1
        // 12 -> 2
        // 123 -> 2
        // 1234 -> 2
        // 1212 -> 3   # 状态转移方程是什么???
        /*
        * 只能由位置 `i` 的单独作为一个 `item`，设为 `a`，转移的前提是 `a` 的数值范围为 *[1,9]*，转移逻辑为 *f[i] = f[i - 1]*。
        * 只能由位置 `i` 的与前一位置（`i-1`）共同作为一个 `item`，设为 `b`，转移的前提是 `b` 的数值范围为 *[10,26]*，转移逻辑为 *f[i] = f[i - 2]*。
        * 位置 `i` 既能作为独立 `item` 也能与上一位置形成 `item`，转移逻辑为 *f[i] = f[i - 1] + f[i - 2]*。

        */
        int n = s.size();
        s = " " + s;
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            // a : 代表[当前位置]单独形成的item
            // b : 代表[当前位置]与[前一个位置]共同形成item
            int a = s[i] - '0';
            int b = (s[i-1] - '0') * 10 + (s[i] - '0');
            // 如果a属于有效值，那么 f[i] 可以由f[i-1]转移过来
            if (1 <= a && a<= 9) dp[i] = dp[i-1];
            // 如果 b 属于有效值，那么f[i]可以由f[i-2] 或者f[i-1] & f[i-2] 转移过来
            if (10 <= b && b <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
