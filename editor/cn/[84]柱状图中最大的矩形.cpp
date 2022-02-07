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
             2. 



             84 和 85 两道题具有类似性
    */
    int largestRectangleArea(vector<int>& heights) {
        // 1. 使用单调栈来解决该问题
        int n = heights.size();

        // 2. 确定左右边界序列
        vector<int> left(n), right(n, n);

        // 3. 开始遍历heights
        stack<int> monoStk; // 单调栈（单调递增） 这个单词不错，可以使用
        for (int i=0; i<n; i++) {
            while (!monoStk.empty() && heights[i] < heights[monoStk.top()]) {
                // 这里需要入右单调栈
                right[monoStk.top()] = i;

                monoStk.pop();
            }

            left[i] = monoStk.empty() ? -1 : monoStk.top();
            monoStk.push(i);
        }


        // 找到最大结果
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = max( ans, (right[i] - left[i] - 1 ) * heights[i] );
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
