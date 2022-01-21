//在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。 
//
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。 
//
// 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。 
//
// 说明: 
//
// 
// 如果题目有解，该答案即为唯一答案。 
// 输入数组均为非空数组，且长度相同。 
// 输入数组中的元素均为非负数。 
// 
//
// 示例 1: 
//
// 输入: 
//gas  = [1,2,3,4,5]
//cost = [3,4,5,1,2]
//
//输出: 3
//
//解释:
//从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//因此，3 可为起始索引。 
//
// 示例 2: 
//
// 输入: 
//gas  = [2,3,4]
//cost = [3,4,3]
//
//输出: -1
//
//解释:
//你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
//我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
//开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
//开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
//你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
//因此，无论怎样，你都不可能绕环路行驶一周。 
// Related Topics 贪心 数组 
// 👍 818 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:

public:
    // gas 加油站拥有的油
    // cost 跑到下一个加油站，需要消耗的油
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    /*
        // 思路：
        // 贪心算法1
        int curSum = 0;
        int min = INT_MAX; // 从起点出发，邮箱里的油量最小值
        for (int i=0; i<gas.size(); i++) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if (curSum < min) {
                min = curSum;
            }
        }

        // 情况⼀：如果gas的总和⼩于cost总和，那么⽆论从哪⾥出发，⼀定是跑不了⼀圈的
        if (curSum < 0) return -1;

        // 情况⼆：rest[i] = gas[i]-cost[i]为⼀天剩下的油，i从0开始计算累加到最后⼀站，如果累加没有出现负数，说
        // 明从0出发，油就没有断过，那么0就是起点。
        if (min >= 0) {
            return 0;
        }

        // 情况三：如果累加的最⼩值是负数，汽⻋就要从⾮0节点出发，从后向前，看哪个节点能这个负数填平，能把
        // 这个负数填平的节点就是出发节点。
        for (int i= gas.size() - 1; i>=0; i--) {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0) {
                return i;
            }
        }

        return -1;
    */
        // 贪心算法2
        // 如果前边小于0，则后边可以补齐
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i=0; i<gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i+1;
                curSum = 0;
            }
        }

        if (totalSum < 0) return -1;
        return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
