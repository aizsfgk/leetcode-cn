//请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。 
//
// 示例 1: 
//
// 
//输入: temperatures = [73,74,75,71,69,72,76,73]
//输出: [1,1,4,2,1,1,0,0]
// 
//
// 示例 2: 
//
// 
//输入: temperatures = [30,40,50,60]
//输出: [1,1,1,0]
// 
//
// 示例 3: 
//
// 
//输入: temperatures = [30,60,90]
//输出: [1,1,0] 
//
// 
//
// 提示： 
//
// 
// 1 <= temperatures.length <= 105 
// 30 <= temperatures[i] <= 100 
// 
// Related Topics 栈 数组 单调栈 
// 👍 1009 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        if (n == 0) {
            return {};
        }
//        if (n == 1) {
//            return {0};
//        }

        /*
        思路:
            单调栈：1. 既可以在入栈之前，操作
                   2. 也可以在出栈之前操作；
                   3. 单调栈多半存的是下标，索引等

            1 - 0 == 1
            2 - 1 == 2

            维护一个单调递减的单调栈；当出战的时候，进行索引差，求得需要几日升温
        */

        vector<int> ans(n, 0); // 最后几个不放入，不就是0???
        stack<int> monoStk;

        for (int i=0; i<n; i++) {
            while (!monoStk.empty() && temperatures[i] > temperatures[monoStk.top()]) {
                int prevIdx = monoStk.top();
                ans[prevIdx] = i - prevIdx;
                monoStk.pop();
            }
            monoStk.push(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
