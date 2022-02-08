//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：heights = [2,1,5,6,2,3]
//输出：10
//解释：最大的矩形为图中红色区域，面积为 10
// 
//
// 示例 2： 
//
// 
//
// 
//输入： heights = [2,4]
//输出： 4 
//
// 
//
// 提示： 
//
// 
// 1 <= heights.length <=105 
// 0 <= heights[i] <= 104 
// 
// Related Topics 栈 数组 单调栈 
// 👍 1716 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
// time: O(n)
// space: O(n)
public:
    /*
        思路：
             1. 以一根柱子为例heights[i]，我们需要找该柱子不小于其高度的柱子，向左右2边扩展；
                换一句话说，就是我们需要找到首次小于该柱子的柱子；这样这两根柱子之间（不包括其本身）的所有柱子
                高度均不小于heights[i]
             2. 所以接下来需要怎么想呢? 我们既要记录 高度， 也要记录宽度，才能计算出面积。宽度可以通过 idx索引确定。
                怎么实现1的扩展呢？这里就需要单调栈了.

                a. 确定左边界: 我们维护一个单调递增的栈，当 当前元素 入栈之前，去掉比自身大的，此时栈顶为左边第一个小于
                   自身的元素；确定左边界索引。 -1 表示最左边界
                b. 确定右边界: 同理可以使用单调栈，从尾部到头部遍历确定右边界。这里使用了取巧的方式，出栈之前 当前元素
                   一定是第一个小于栈顶的右边的第一个元素。

             3. left 没有 则为 -1 左辩解极限了；right 没有则为 n 右边界极限了。


             84 和 85 两道题具有类似性
    */
    int largestRectangleArea(vector<int>& heights) {
        // 1. 使用单调栈来解决该问题
        int n = heights.size();

        // 2. 确定左右边界序列
        vector<int> left(n), right(n, n); // right 初始化为 n

        // 3. 开始遍历heights
        stack<int> monoStk; // 单调栈（单调递增） 这个单词不错，可以使用；// 单调栈里存的是索引
        for (int i=0; i<n; i++) {
            while (!monoStk.empty() && heights[i] < heights[monoStk.top()]) {
                // 这里需要入右单调栈
                // 右边比它小的第一个下标
                right[monoStk.top()] = i;

                monoStk.pop();
            }

            // 左边界：第一个比它本身小的下标
            // 为何可以使用-1 ????
            left[i] = monoStk.empty() ? -1 : monoStk.top();

            //
            monoStk.push(i);
        }


        // 因为 左右都存的是最小的索引，所以 相当于 (j-i+1) - 2 => j-i-1
        // 找到最大结果
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = max( ans, (right[i] - left[i] - 1 ) * heights[i] );
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
