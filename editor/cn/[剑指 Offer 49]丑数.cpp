//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。 
//
// 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
//
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ 
// Related Topics 哈希表 数学 动态规划 堆（优先队列） 
// 👍 349 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
        1. 小根堆 + set
        2. 小根堆拿到最小值
        3. set 防止重复元素添加到小根堆中

    */
    /*
    int factors[3] = {2, 3, 5};
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> que; // 小根堆
        unordered_set<long> search;

        que.push(1L);
        search.insert(1L);

        long ans = 0;
        for (int i=0; i<n; i++) {
            ans = que.top(); que.pop();

            for (int num : factors) {
                long now = num * ans;
                if (!search.count(now)) {
                    que.push(now);
                    search.insert(now);
                }
            }
        }
        return (int)ans;


        // DP 方法
    }
    */
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i=1;i<n; i++) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(n2, min(n3, n5));

            if (dp[i] == n2)
                a++;
            if (dp[i] == n3)
                b++;
            if (dp[i] == n5)
                c++;
        }
        return dp[n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
