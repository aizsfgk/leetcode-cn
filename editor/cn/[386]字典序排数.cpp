//给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。 
//
// 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 13
//输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
// 
//
// 示例 2： 
//
// 
//输入：n = 2
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 5 * 104 
// 
// Related Topics 深度优先搜索 字典树 
// 👍 307 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 13
    // [1,10,11,12,13,2,3,4,5,6,7,8,9]
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int number = 1;
        for (int i=0; i<n; i++) {
            ans[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            } else {

                // while 语法
                while (number % 10 == 9 || number+1 > n) {
                    number /= 10;
                }

                number++;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
