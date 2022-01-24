//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。 
//
// 注意: 
//
// 
// 可以认为区间的终点总是大于它的起点。 
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。 
// 
//
// 示例 1: 
//
// 
//输入: [ [1,2], [2,3], [3,4], [1,3] ]
//
//输出: 1
//
//解释: 移除 [1,3] 后，剩下的区间没有重叠。
// 
//
// 示例 2: 
//
// 
//输入: [ [1,2], [1,2], [1,2] ]
//
//输出: 2
//
//解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
// 
//
// 示例 3: 
//
// 
//输入: [ [1,2], [2,3] ]
//
//输出: 0
//
//解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
// 
// Related Topics 贪心 数组 动态规划 排序 
// 👍 587 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 思路
        // 移除区间
        if (intervals.size() == 0) return 0;

        // 排序
        sort(intervals.begin(), intervals.end(), cmp);

        int ans = 1;
        for (int i=1; i<intervals.size(); i++) {
            // 解决
            if (intervals[i][0] >= intervals[i-1][1]) { // 这里是 >=
                ans++; // 求出非交叉的去区间
            } else {
                intervals[i][1] = min(intervals[i-1][1], intervals[i][1]);
            }
        }

        return intervals.size() - ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
