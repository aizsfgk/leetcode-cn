//给定一个数字字符串 num，比如 "123456579"，我们可以将它分成「斐波那契式」的序列 [123, 456, 579]。 
//
// 形式上，斐波那契式 序列是一个非负整数列表 f，且满足： 
//
// 
// 0 <= f[i] < 2³¹ ，（也就是说，每个整数都符合 32 位 有符号整数类型） 
// f.length >= 3 
// 对于所有的0 <= i < f.length - 2，都有 f[i] + f[i + 1] = f[i + 2] 
// 
//
// 另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。 
//
// 返回从 num 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。 
//
// 
//
// 示例 1： 
//
// 
//输入：num = "1101111"
//输出：[11,0,11,11]
//解释：输出[110,1,111]也可以。 
//
// 示例 2： 
//
// 
//输入: num = "112358130"
//输出: []
//解释: 无法拆分。
// 
//
// 示例 3： 
//
// 
//输入："0123"
//输出：[]
//解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num.length <= 200 
// num 中只含有数字 
// 
// Related Topics 字符串 回溯 👍 257 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // pre2, pre
    // dfs
    // 和累加数类似

    // 可能的结果
    vector<int> ans;
    // 结果结合中的一个结果
    vector<int> path;

    // 前1/前2个数
    void backtracking(const string &num, int idx, int count, long long prev2, long long prev) {

        // 索引结束、个数符合
        if (idx >= num.size() && count >= 3) {
            ans = path;
            return;
        }

        long long cur = 0;
        for (int i=idx; i<num.size(); i++) {

            if (num[idx] == '0' && i > idx) {
                // 剪枝1：不能作为前导0，但是可以单独作为0使用
                return;
            }

            cur = cur * 10 + (num[i] - '0');
            if (cur > INT_MAX) // 2. 大于INT_MAX 剪枝
                return;

            if (count >= 2) {
                long long sum = prev2 + prev;
                if (sum > INT_MAX) // 3. sum > INT_MAX ，剪枝
                    return;

                if (cur > sum) return; // 4. 当前大于 剪枝

                if (cur < sum) continue; // 5. 小于，还能增加数字
            }

            path.push_back((int)cur);
            backtracking(num, i+1, count+1, prev, cur);
            path.pop_back();
        }
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        if (num.size() < 3) return ans;

        backtracking(num, 0, 0, 0, 0);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
