//在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横
//坐标就足够了。开始坐标总是小于结束坐标。 
//
// 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足 xsta
//rt ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的
//最小数量。 
//
// 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。 
// 
//
// 示例 1： 
//
// 
//输入：points = [[10,16],[2,8],[1,6],[7,12]]
//输出：2
//解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球 
//
// 示例 2： 
//
// 
//输入：points = [[1,2],[3,4],[5,6],[7,8]]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：points = [[1,2],[2,3],[3,4],[4,5]]
//输出：2
// 
//
// 示例 4： 
//
// 
//输入：points = [[1,2]]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：points = [[2,3],[2,3]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= points.length <= 104 
// points[i].length == 2 
// -231 <= xstart < xend <= 231 - 1 
// 
// Related Topics 贪心 数组 排序 
// 👍 509 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // 这个比较函数 static 必须是静态的
    static bool cmp(vector<int> &a, vector<int> &b) {
        return  a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 思路：
        //   局部最优：当将气球重叠，射出的箭最少
        //   全局最优: 使用该方法，引爆所有的箭则最少
        //
        // 步骤：
        //  1. 排序
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);

        // 开始遍历
        int ans = 1;
        for (int i=1; i<points.size(); i++) {
            // 如果两排气球不挨着，则箭+1
            if (points[i][0] > points[i-1][1]) {
                ans++;
            } else { // 两排气球挨着，则更新最小右边界
                // 为之后使用
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
