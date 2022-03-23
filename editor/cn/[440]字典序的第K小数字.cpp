//给定整数 n 和 k，返回 [1, n] 中字典序第 k 小的数字。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = 13, k = 2
//输出: 10
//解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
// 
//
// 示例 2: 
//
// 
//输入: n = 1, k = 1
//输出: 1
// 
//
// 
//
// 提示: 
//
// 
// 1 <= k <= n <= 109 
// 
// Related Topics 字典树 
// 👍 355 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
/*
    怎么确定一个前缀下所有子节点的个数？
    如果第 k 个数在当前的前缀下，怎么继续往下面的子节点找？
    如果第 k 个数不在当前的前缀，即当前的前缀比较小，如何扩大前缀，增大寻找的范围？

*/
public:
    long getCount(long prefix, long n) {
        long cur = prefix;
        long next = cur + 1;
        long count = 0;
        while (cur <= n) {
            count += min(n+1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        // topK 问题
        long p = 1;
        long prefix = 1;
        while (p < k) {
            long count = getCount(prefix, n);
            if (p + count > k) {
                // 说明第K个数，在这个前缀范围内
                prefix *= 10;
                p++;
            } else if (p+count <= k) {
                // 说明第k个数，不在这个前缀范围里面，前缀需要扩大+1
                prefix++;
                p += count;
            }
        }
        return static_cast<int>(prefix);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
