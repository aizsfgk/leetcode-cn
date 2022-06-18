//你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能
//折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。 
//
// 如果你能使这个正方形，则返回 true ，否则返回 false 。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: matchsticks = [1,1,2,2,2]
//输出: true
//解释: 能拼成一个边长为2的正方形，每边两根火柴。
// 
//
// 示例 2: 
//
// 
//输入: matchsticks = [3,3,3,3,4]
//输出: false
//解释: 不能用所有火柴拼成一个正方形。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= matchsticks.length <= 15 
// 1 <= matchsticks[i] <= 10⁸ 
// 
// Related Topics 位运算 数组 动态规划 回溯 状态压缩 👍 414 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
/*
    本题和划分为K个相等的子集算法一致

*/
private:
    int target;

    bool dfs(const vector<int> &matchsticks, vector<int> &used, int idx, int kSum, int k) {
        // 说明正好符合条件
        if (k == 0) {
            return true;
        }


        for (int i=idx; i<matchsticks.size(); i++) {

            if (used[i] == 1) { // 被选过，则跳过；正常逻辑
                continue;
            }

            // 同样的数字，上次没用，这次也不应该用
            if (i > 0 && matchsticks[i-1] == matchsticks[i] && !used[i-1]) {
                continue;
            }

            int tmp = kSum + matchsticks[i]; // 加上本次的数

            if (tmp > target) { // 大于目标，跳过
                continue;
            }

            // 根据和是否等于目标，决定下一轮的参数情况
            int nextIdx = (tmp == target) ? 0 : i+1;  // 等于
            int nextKSum = tmp == target ? 0 : tmp;
            int nextK = tmp == target ? k-1 : k;

            used[i] = 1;
            if (dfs(matchsticks, used, nextIdx, nextKSum, nextK)) { return true; }
            used[i] = 0;

        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        // 等分到四个桶里边
        int n = matchsticks.size();
        if (n < 4) return false;

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;

        target = sum / 4;

        vector<int> used(n);
        return dfs(matchsticks, used, 0, 0, 4);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
