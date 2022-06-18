//累加数 是一个字符串，组成它的数字可以形成累加序列。 
//
// 一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。 
//
// 给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。 
//
// 说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。 
//
// 
//
// 示例 1： 
//
// 
//输入："112358"
//输出：true 
//解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// 
//
// 示例 2： 
//
// 
//输入："199100199"
//输出：true 
//解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199 
//
// 
//
// 提示： 
//
// 
// 1 <= num.length <= 35 
// num 仅由数字（0 - 9）组成 
// 
//
// 
//
// 进阶：你计划如何处理由过大的整数输入导致的溢出? 
// Related Topics 字符串 回溯 👍 363 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /*
        string dfs : 字符串深度优先遍历

    */
public:
    bool isAdditiveNumber(string num) {
        return dfs(num, 0, 0, 0, 0);
    }

    bool dfs(const string &num, int idx, int count, long long prev2,long long prev) {
        // 个数大于2, 返回true
        if (idx >= num.size()) { // 终止条件
            return count > 2;
        }

        long long current = 0;
        for (int i=idx; i<num.size(); i++) {
            char c = num[i];

            if (num[idx] == '0' && i > idx) {
                // 剪枝1：不能作为前导0，但是可以单独作为0使用
                return false;
            }

            current = current * 10 + (c - '0');

            if (current > (1e18 - 1)) //防止溢出 这是17位的9
                return false;

            if (count >= 2) {
                long long sum = prev2 + prev;
                if (current > sum) {
                    // 剪枝2： 如果当前数比之前两数的和大了，说明不合适
                    return false;
                }

                if (current < sum) {
                    // 剪枝3：如果当前数比之前两数的和小了，说明还不够，可以继续添加新的字符进来
                    continue;
                }

                // 其他继续dfs
            }

            // 迭代返回
            if (dfs(num, i+1, count+1, prev, current)) {
                return true;
            }

        }

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
